#include "numbases.h"

int from_octal(char* message, size_t len, size_t i) {
    if (i == len) return -1;

    char c = message[i];
    int v = 0;
    if (c < '0' || c > '7') return -1;
    v += c - '0';

    if (i == len - 1) return v;

    c = message[i+1];
    if (c < '0' || c > '7') return v;
    v <<= 3;
    v += c - '0';

    if (i == len - 2 || message[i] > '3') return v;

    c = message[i+2];
    if (c < '0' || c > '7') return v;
    v <<= 3;
    v += c - '0';

    return v;
}

int from_hex(char* message, size_t len, size_t i) {
    if (i == len) return -1;

    char c = message[i];
    int v = 0;
    if (c < '0' || (c > '9' && c < 'A') || (c > 'F' && c < 'a') || c > 'f') return -1;
    if (c <= '9') v += c - '0';
    else if (c < 'G') v += c - 'A' + 10;
    else if (c < 'g') v += c - 'a' + 10;

    if (i == len - 1) return v;

    c = message[i+1];
    if (c < '0' || (c > '9' && c < 'A') || (c > 'F' && c < 'a') || c > 'f') return v;
    v <<= 4;
    if (c <= '9') v += c - '0';
    else if (c < 'G') v += c - 'A' + 10;
    else if (c < 'g') v += c - 'a' + 10;

    return v;
}