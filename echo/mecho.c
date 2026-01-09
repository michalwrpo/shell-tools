#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "numbases.h"
#include "strnum.h"

#include "mecho.h"

int set_flags(int argc, char** argv, int flags[MECHO_FLAGS_COUNT]) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') return i;

        for (size_t j = 1; j < strlen(argv[i]); j++) {
            switch (argv[i][j]) {
            case 'c': 
                if (i == argc - 1) return i;

                long long repeats = string_to_ll(argv[i+1], strlen(argv[i+1]));
                if (j < strlen(argv[i]) - 1 || repeats < 0) {
                    fprintf(stderr, "No number after -c flag\n");
                    return i+1;
                }
                
                flags[2] = repeats + 1;
                i++;
                break;
            case 'e': flags[1] = 1; break;
            case 'n': flags[0] = 1; break;
            case 'r': flags[3] = 1; break;
            default: 
                if (j > 1) {
                    fprintf(stderr, "Unknown flag: %c\n", argv[i][j]);
                    return i + 1; 
                }
                return i;
                break;
            }
        }
    }

    return argc;
}


int mecho(char* message, int flags[MECHO_FLAGS_COUNT]) {
    long long k = 0, repeats = flags[2] ? flags[2] - 1 : 1;

    while (k++ < repeats || flags[3]) {
        if (!flags[1]) {
            printf("%s", message);
        } else {
            int num;
            size_t len = strlen(message);
            for (size_t i = 0; i < len; i++) {
                if (message[i] == '\\' && i < len - 1) {
                    switch (message[i+1]) {
                    case '0': 
                        num = from_octal(message, len, i+2);
                        if (num == -1) {
                            printf("\\x");
                        } else {
                            i++;
                            if (num > 7) i++;
                            if (num > 63) i++;
                            printf("%c", num);
                        }
                        break;
                    case 'b': printf("\b"); break;
                    case 'e': printf("\e"); break;
                    case 'n': printf("\n"); break;
                    case 't': printf("\t"); break;
                    case 'v': printf("\v"); break;
                    case 'x': 
                        num = from_hex(message, len, i+2);
                        if (num == -1) {
                            printf("\\x");
                        } else {
                            i++;
                            if (num > 15) i++;
                            printf("%c", num);
                        }
                        break;
                    
                    default:
                        printf("%c%c", message[i], message[i + 1]);
                        break;
                    }
                    i++;
                } else {
                    printf("%c", message[i]);
                }
            }
        }
        
        if (!flags[0]) printf("\n");
    }

    return 0;
}

int main(int argc, char** argv) {
    int flags[MECHO_FLAGS_COUNT], i, index, exit_code;
    for (i = 0; i < MECHO_FLAGS_COUNT; i++) flags[i] = 0;

    index = set_flags(argc, argv, flags);

    if (index >= argc) {
        exit_code = mecho("", flags);
        return exit_code;
    }
    
    int message_len = 0;
    for (i = index; i < argc; i++) message_len += 1 + strlen(argv[i]);
    
    char* message = malloc(sizeof(char) * message_len);
    strcpy(message, argv[index]);

    for (i = index + 1; i < argc; i++) {
        strcat(message, " "); 
        strcat(message, argv[i]);
    }
    message[message_len - 1] = '\0';

    exit_code = mecho(message, flags);

    free(message);

    return exit_code;
}