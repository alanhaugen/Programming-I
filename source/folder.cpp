#include "folder.h"
#include <iostream>

using namespace std;

void Folder::Init()
{
    folderQuantity = 0;
    fileQuantity = 0;
    parentFolder = NULL;
}

Folder::Folder()
{
    Init();
}

Folder::Folder(string _name)
{
    name = _name;

    Init();
}

bool Folder::AddFolder()
{
    if (folderQuantity < MAX_FOLDERS)
    {
        return true;
    }

    return false;
}

bool Folder::AddFile()
{
    if (fileQuantity < MAX_FILES)
    {
        return true;
    }

    return false;
}

void Folder::PrintList()
{
    // todo: sort by largest folder...
    for (unsigned int i = 0; i < folderQuantity; i++)
    {
        cout << "- folder: " << folders[i].name << "\t" << folders[i].sizeInMB <<
                folders[i].dateOfCreation << folders[i].dateOfCreation << "\n";
    }

    // todo: sort by largest file...
    for (unsigned int i = 0; i < fileQuantity; i++)
    {
        cout << files[i].name << "\t" << files[i].sizeInMB <<
                files[i].dateOfCreation << files[i].dateOfCreation << "\n";
    }
}

void Folder::PrintWorkingDirectory()
{
    if (parentFolder == NULL)
    {
        cout << name << endl;
    }
}

int Folder::GetSizeInMB()
{
    return 0;
}
