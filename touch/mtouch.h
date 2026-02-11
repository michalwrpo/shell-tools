#ifndef MTOUCH_H
#define MTOUCH_H

#define MTOUCH_FLAG_COUNT 2

/// @brief changes the modification and access time of the given file
/// @param file_name name of a file to touch 
/// @param flags 
/// 0 (-m) - change only modification time
/// 1 (-a) - change only access time
/// @return exit code
int mtouch(const char* file_name, int flags[MTOUCH_FLAG_COUNT]);

#endif // MTOUCH_H