#include <stdio.h>

#include "mmkdir.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s directory_name ...\n", argv[0]);
        return 1;
    }

    int exit_code = 0;

    for (int i = 1; i < argc; ++i) {
        int tmp;
        if ((tmp = mmkdir(argv[i]))) exit_code = tmp;
    }

    return exit_code;
}