#include "mcat.h"

int main(int argc, char** argv) {
    int exitcode = mcat(argc - 1, &(argv[1]));

    return exitcode;
}