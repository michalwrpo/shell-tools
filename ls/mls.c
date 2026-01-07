#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#include "mls.h"

void print(char* filename, int flags[1], int one) {
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(filename)) == NULL) {
        printf("%s  ", filename);
        if (flags[0]) printf("\n");
    } else {
        if (!one) printf("%s:\n", filename);
        while ((dp = readdir(dfd)) != NULL) {
            printf("%s  ", dp->d_name);
            if (flags[0]) printf("\n");
        }
        if (!flags[0]) printf("\n");

        closedir(dfd);
    }
    
}

int mls(char **files, int fileno, int flags[1]) {
    char *fname;
    int i, j = 0, k = 0, one = 1;

    char **dirs;
    char **fs;

    struct stat sb;

    if (fileno == 0) {
        print(".", flags, one);
        return 0;
    } else {
        dirs = malloc(sizeof(char*) * fileno);
        fs = malloc(sizeof(char*) * fileno);


        for (i = 0; i < fileno; i++) {
            fname = files[i];
            if (stat(fname, &sb) == -1) {
                fprintf(stderr, "Can't locate '%s'\n", fname);
            } else {
                if ((sb.st_mode & S_IFMT) == S_IFDIR) {
                    dirs[j++] = fname;
                } else {
                    fs[k++] = fname;
                }
            }
        }
    }

    for (i = 0; i < k; i++) {
        print(fs[i], flags, 0);
    }
    if (!(flags[0]) && k) printf("\n");

    free(fs);

    if (j + k > 1) one = 0;

    for (i = 0; i < j; i++) {
        if (i + k > 0) printf("\n");
        print(dirs[i], flags, one);
    }

    free(dirs);

    return 0;
}


int main(int argc, char** argv) {
    int fileno = 0, i, len;
    char** files = malloc(sizeof(char*) * argc);

    /*
    Options available
    -1 - prints one file per line
    */
    int flags[1] = {0};

    
    for (i = 1; i < argc; i++) {
        len = strlen(argv[i]);
        if (len < 2) {
            files[fileno] = malloc(sizeof(char) * (len + 1));
            strcpy(files[fileno], argv[i]);
            fileno++;
            continue;
        }

        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
            case '1': flags[0] = 1; break;
            default: fprintf(stderr, "Invalid option %s\n", argv[i]); exit(EXIT_FAILURE); break;
            }
            continue;
        } 

        files[fileno] = malloc(sizeof(char) * (len + 1));
        strcpy(files[fileno], argv[i]);
        fileno++;
    }

    files = realloc(files, sizeof(char*) * fileno);

    if (!files) {
        perror("realloc failure");
        exit(EXIT_FAILURE);
    }
    
    int exit_code = mls(files, fileno, flags);

    for (i = 0; i < fileno; i++) free(files[i]);
    free(files);

    return exit_code;
}
