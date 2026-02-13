#ifndef MYES_H
#define MYES_H

/// @brief repeatidly outputs "y" or a given message.
/// @param count number of strings in `messages`
/// @param messages phrases to repeat instead of "y", "y" if NULL
/// @return exit code
int myes(int count, char** messages);

#endif // MYES_H