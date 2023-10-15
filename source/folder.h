#ifndef FOLDER_H
#define FOLDER_H

#include "file.h"

const unsigned int MAX_FILES   = 10;
const unsigned int MAX_FOLDERS = 5;

class Folder : public Info
{
private:
    unsigned int folderQuantity;
    unsigned int fileQuantity;

    void Init();

public:
    File files[MAX_FILES];
    Folder *folders; // maximum of 5

    Folder();
    Folder(string _name);

    bool AddFolder();
    bool AddFile();

    void PrintList();
    int GetSizeInMB();
};

#endif // FOLDER_H
