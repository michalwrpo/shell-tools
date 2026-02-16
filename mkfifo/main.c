#include <stdio.h>

#include "mmkfifo.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "mkfifo: missing operand\n");
        return 1;
    }

    int exitcode = mmkfifo(argc - 1, &(argv[1]));

    return exitcode;
}