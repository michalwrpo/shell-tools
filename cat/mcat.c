#include <stdio.h>
#include <unistd.h>

#include "mcat.h"

int mcat(int fileno, char** files) {
    int exit_code = 0;
    
    if (fileno > 0) {
        char line[256];
        for (int i = 0; i < fileno; i++) {
            FILE* file = fopen(files[i], "r");

            if (!file) {
                fprintf(stderr, "mcat: %s: ", files[i]);
                perror("");
                exit_code = 1;
                continue;
            }

            while (fgets(line, sizeof(line), file)) {
                printf("%s", line);
            }

            fclose(file);
        }

        return exit_code;
    }

    char c[1];

    while(read(STDIN_FILENO, c, 1)) {
        printf("%s", c);
    }

    return exit_code;
}
