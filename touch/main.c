#include <stdio.h>

#include "mtouch.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s FILE ...\n", argv[0]);
        return 1;
    }

    int exit_code = 0;

    for (int i = 1; i < argc; ++i) {
        int tmp;
        if ((tmp = mtouch(argv[i]))) exit_code = tmp;
    }

    return exit_code;
}