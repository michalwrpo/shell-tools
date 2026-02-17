#include <stdlib.h>
#include <unistd.h>

#include "mexec.h"

int mexec(int argc, char** argv) {
    char** args = malloc(sizeof(char*) * (argc + 1));

    for (int i = 0; i < argc; i++) args[i] = argv[i];

    args[argc] = (char*) NULL;

    return execvp(args[0], args);
}
