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
    Folder* parentFolder;

    void Init();

public:
    File files[MAX_FILES];
    Folder *folders;

    Folder();
    ~Folder();
    Folder(string _name);

    bool AddFolder(string foldername);
    bool AddFile(string filename);

    bool MoveFileOrFolder(string filename, string newname);

    void PrintList();
    void PrintRecursive(Folder* ptr);
    void PrintWorkingDirectory();
    void PrintLargestFileInfo();
    int GetSizeInMB();
    Folder* GetFolder(string foldername);
};

#endif // FOLDER_H
