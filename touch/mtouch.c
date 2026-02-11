#include <stdio.h>
#include <time.h>
#include <utime.h>
#include <sys/stat.h>

#include "mtouch.h"

int mtouch(const char* file_name, int flags[MTOUCH_FLAG_COUNT]) {
    time_t ntime = time(NULL);
    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        file = fopen(file_name, "a");
        return fclose(file);
    }

    fclose(file);

    struct stat s;
    struct utimbuf new_times;
    
    stat(file_name, &s);

    if (flags[0]) new_times.modtime = ntime;
    else new_times.modtime = s.st_mtim.tv_sec;

    if (flags[1]) new_times.actime = ntime;
    else new_times.actime = s.st_atim.tv_sec;

    int exit_code = utime(file_name, &new_times);

    return exit_code;
}
