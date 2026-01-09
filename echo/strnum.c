#include "strnum.h"

long long string_to_ll(char* str, int strlen) {
    long long v = 0;
    char c;

    for (int i = 0; i < strlen; i++) {
        c = str[i];
        if (c < '0' || c > '9') return -1;
        v *= 10;
        v += c - '0';
    }
    
    return v;
}
