#include <stdio.h>
#include <utime.h>

#include "mtouch.h"

int mtouch(const char* file_name) {
    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        file = fopen(file_name, "a");
        return fclose(file);
    }

    fclose(file);

    int exit_code = utime(file_name, NULL);

    return exit_code;
}
