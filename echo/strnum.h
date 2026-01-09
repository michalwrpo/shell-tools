#ifndef STRNUM_H
#define STRNUM_H

/// @brief converts a string to long long (only positive values)
/// @param str input string 
/// @param strlen length of the string
/// @return value of number in the string, -1 if string does not represent a number
long long string_to_ll(char* str, int strlen);

#endif // STRNUM_H