#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#include "mtee.h"

/*
Implementation of mtee was deliberately made harder as an exercise.
Therefore, it creates multiple processes with fork() and each process
only writes to 1 file and input of pipe to next process.
*/

int mtee(int fileno, char** files) {
    const int BSIZE = 256;
    char* buf[BSIZE];
    int n;

    if (fileno == 0) {
        while ((n = read(STDIN_FILENO, buf, BSIZE))) {
            write(STDOUT_FILENO, buf, n);
        }

        return 0;
    }

    int p1[2], p2[2];
    int status, i;
    pid_t cpid;
    int fd;

    
    for (i = 0; i < fileno; i++) {
        if (i % 2 == 0) status = pipe(p1);
        else status = pipe(p2);
    
        if (status == -1) {
            perror("mtee");
        }

        cpid = fork();
        
        if (cpid == -1) {
            perror("mtee");
        }

        if (cpid == 0) {
            // write end unused
            if (i % 2 == 0) {
                close(p1[1]);
                if (i) close(p2[0]); // close parent's input
            } else {
                close(p2[1]);
                close(p1[0]); // close parent's input
            } 

            fd = open(files[i], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

            if (fd == -1) {
                fprintf(stderr, "mtee: %s: ", files[i]);
                perror("");
                exit(EXIT_FAILURE);
            }
        } else {
            // read end unused
            if (i % 2 == 0) close(p1[0]);
            else close(p2[0]); 
            break; // exit from loop
        }
    }

    if (i == 0) {
        while ((n = read(STDIN_FILENO, buf, BSIZE))) {
            write(STDOUT_FILENO, buf, n);
            write(p1[1], buf, n);
        }
        close(p1[1]);
    } else {
        if (i % 2 == 1) {
            while ((n = read(p1[0], buf, BSIZE))) {
                write(fd, buf, n);
                if (i < fileno) write(p2[1], buf, n);
            }

            close(p1[0]);
            if (i < fileno) close(p2[1]);
        } else {
            while ((n = read(p2[0], buf, BSIZE))) {
                write(fd, buf, n);
                if (i < fileno) write(p1[1],buf, n);
            }

            close(p2[0]);
            if (i < fileno) close(p1[1]);
        }

        close(fd);
    }

    if (i == fileno) return 0;

    waitpid(cpid, &status, 0);

    if (status) exit(EXIT_FAILURE);

    return 0;
}
