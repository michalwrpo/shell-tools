#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "mmkfifo.h"

int mmkfifo(int count, char** names) {
    int exit_code = 0;

    for (int i = 0; i < count; i++) {
        if (mkfifo(names[i], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) {
            exit_code = 1;
            fprintf(stderr, "mmkfifo: %s: ", names[i]);
            perror("");
        }
    }
    
    return exit_code;
}
