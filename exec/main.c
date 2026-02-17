#include "mexec.h"

int main(int argc, char** argv) {
    int exitcode = mexec(argc - 1, &(argv[1]));

    return exitcode;
}