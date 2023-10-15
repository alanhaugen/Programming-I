#include "file.h"

#include <stdlib.h>

File::File()
{
    name = "none";
    sizeInMB = arc4random() % 100;
    dateOfCreation = 2023;
}
