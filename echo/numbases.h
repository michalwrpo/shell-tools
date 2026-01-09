#ifndef NUMBASES_H
#define NUMBASES_H

#include <stdlib.h>

/// @brief converts max 3 digits of a number in octal base to an int (to max value of 255)
/// @param message string where to look for digits
/// @param len string length
/// @param i starting index
/// @return integer value
int from_octal(char* message, size_t len, size_t i);

/// @brief converts max 2 digits of hex to an int
/// @param message string where to look for hex
/// @param len string length
/// @param i starting index
/// @return integer value
int from_hex(char* message, size_t len, size_t i);

#endif // NUMBASES_H