#include "file.h"

#include <stdlib.h>

File::File()
{
    sizeInMB = arc4random() % 100;
}
