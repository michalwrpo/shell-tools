#ifndef MECHO_H
#define MECHO_H

#define MECHO_FLAGS_COUNT 4

/// @brief Prints the given message to the stdout.
/// @param message text to be displayed
/// @param flags array of value of flags:
/// 0 (-n) - no newline,
/// 1 (-e) - format escape characters,
/// 2 (-c) - number of times the message should be printed,
/// 3 (-r) - repeat the message 
/// @return exit code
int mecho(char* message, int flags[MECHO_FLAGS_COUNT]);

#endif // MECHO_H