#ifndef MEXEC_H
#define MEXEC_H

/// @brief executes a command with given args
/// @param argc number of arguments
/// @param argv arguments (first should be the name of command)
/// @return exit code
int mexec(int argc, char** argv);

#endif // MEXEC_H