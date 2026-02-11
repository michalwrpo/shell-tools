#ifndef MMKDIR_H
#define MMKDIR_H

/// @brief creates a directory
/// @param path to the directory to be created, null-terminated string
/// @return exit code
int mmkdir(const char* dir_name);

#endif // MMKDIR_H