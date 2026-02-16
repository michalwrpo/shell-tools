#ifndef MTEE_H
#define MTEE_H

/// @brief reads from stdin and write to stdout and given files
/// @param fileno number of files
/// @param files filenames
/// @return exit code
int mtee(int fileno, char** files);

#endif // MTEE_H