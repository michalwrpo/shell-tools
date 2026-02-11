#ifndef MTOUCH_H
#define MTOUCH_H

/// @brief changes the modification and access time of the given file
/// @param file_name name of a file to touch 
/// @return exit code
int mtouch(const char* file_name);

#endif // MTOUCH_H