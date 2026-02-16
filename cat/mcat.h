#ifndef MCAT_H
#define MCAT_H

/// @brief outputs concatenated files to stdout
/// @param fileno number of files
/// @param files array of files
/// @return exit code
int mcat(int fileno, char** files);

#endif // MCAT_H