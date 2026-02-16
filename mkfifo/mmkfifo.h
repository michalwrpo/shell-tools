#ifndef MMKFIFO_H
#define MMKFIFO_H

/// @brief make FIFOs
/// @param count of FIFOs
/// @param names array of FIFOs' names
/// @return exit code
int mmkfifo(int count, char** names);

#endif // MMKFIFO_H