#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "mmkdir.h"

int mmkdir(const char *path) {
    int exit_code = 0;
    if ((exit_code = mkdir(path, 0744))) {
        fprintf(stderr, "mmkdir: cannot create directory '%s': ", path);
        perror("");
        return exit_code;
    }

    return 0;
}
