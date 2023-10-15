#ifndef FILE_H
#define FILE_H

#include <string>

using namespace std;

class Info
{
public:
    string name;
    int sizeInMB;
    string dateOfCreation;
};

class File : public Info
{
public:
    File();
};

#endif // FILE_H
