#include "file.h"

#include <stdlib.h>
#include <cstring>
#include <chrono>
#include <ctime>

/// File Constructor
///
/// This is the only method for File
/// All it does it set a random filesize
/// and set the date of creation
File::File()
{
    name = "none";
    sizeInMB = rand() % 100;

    auto end = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(end);

    char* time = ctime(&end_time);
    if (time[strlen(time)-1] == '\n') time[strlen(time)-1] = '\0';

    dateOfCreation = time;
}
