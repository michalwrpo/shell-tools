#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#include "myes.h"

void stop(int sig) {
    if (sig == SIGPIPE || sig == SIGINT) {
        exit(0);
    }
}

int myes(int count, char** messages) {
    signal(SIGPIPE, stop);

    if (messages == NULL || count == 0) {
        while (1) printf("y\n");
    } else {
        while (1) {
            for (int i = 0; i < count; i++) {
                printf("%s ", messages[i]);
            }
            printf("\n");
        }
    }

    return 0;
}