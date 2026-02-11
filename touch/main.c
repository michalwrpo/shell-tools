#include <stdio.h>
#include <string.h>

#include "mtouch.h"

int set_flags(int argc, char** argv, int flags[MTOUCH_FLAG_COUNT]) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            for (size_t j = 1; j < strlen(argv[i]); j++) {
                switch (argv[i][j]) {
                case 'a':
                    flags[1] = 1;
                    break;
                case 'm':
                    flags[0] = 1;
                    break;
                default:
                    fprintf(stderr, "mtouch: Unknown flag %s\n", argv[i]);
                    return 1;
                    break;
                }
            }
        }
    }

    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s FILE ...\n", argv[0]);
        return 1;
    }
    int flags[MTOUCH_FLAG_COUNT];
    int exit_code = 0;

    for (int i = 0; i < MTOUCH_FLAG_COUNT; i++) flags[i] = 0;

    exit_code = set_flags(argc, argv, flags);

    if (exit_code) return exit_code;

    if (!flags[0] && !flags[1]) { // if no -m or -a modify both
        flags[0] = 1;
        flags[1] = 1;
    }

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') continue;

        int tmp;
        if ((tmp = mtouch(argv[i], flags))) exit_code = tmp;
    }

    return exit_code;
}