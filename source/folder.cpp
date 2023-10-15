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

Folder::~Folder()
{
    delete[] folders;
}

bool Folder::AddFolder(string foldername = "empty")
{
    if (folderQuantity < MAX_FOLDERS)
    {
        Folder *tempFolders = new Folder[folderQuantity + 1];
        tempFolders[folderQuantity].name = foldername;

        for (unsigned int i = 0; i < folderQuantity; i++)
        {
            tempFolders[i] = folders[i];
        }

        delete[] folders;

        folders = tempFolders;

        folderQuantity++;

        return true;
    }

    return false;
}

bool Folder::AddFile(string filename = "none")
{
    if (fileQuantity < MAX_FILES)
    {
        files[fileQuantity] = File();
        files[fileQuantity].name = filename;
        fileQuantity++;

        return true;
    }

    return false;
}

void Folder::PrintList()
{
    cout << "name" << "\t" << "size" << "\t" << "creation" << endl;

    // todo: sort by largest folder...
    for (unsigned int i = 0; i < folderQuantity; i++)
    {
        cout << "- folder: " << folders[i].name << "\t" << folders[i].sizeInMB << "\t" <<
                folders[i].dateOfCreation << "\n";
    }

    // todo: sort by largest file...
    for (unsigned int i = 0; i < fileQuantity; i++)
    {
        cout << files[i].name << "\t" << files[i].sizeInMB << "\t" <<
                files[i].dateOfCreation << "\n";
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
