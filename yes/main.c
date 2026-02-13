#include <stdio.h>
#include <string.h>

#include "myes.h"

int main(int argc, char** argv) {
    if (argc == 1) myes(0, NULL);
    else myes(argc - 1, &(argv[1]));

    return 0;
}