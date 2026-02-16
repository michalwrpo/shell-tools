#include "mtee.h"

int main(int argc, char** argv) {
    int exitcode = mtee(argc - 1, &(argv[1]));

    return exitcode;
}