#include "folder.h"
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <chrono>

using namespace std;

void Folder::Init()
{
    folderQuantity = 0;
    fileQuantity = 0;
    parentFolder = NULL;
    folders = NULL;

    auto end = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(end);

    char* time = ctime(&end_time);
    if (time[strlen(time)-1] == '\n') time[strlen(time)-1] = '\0';

    dateOfCreation = time;
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
        Folder* tempFolders = new Folder[folderQuantity + 1];
        tempFolders[folderQuantity].name = foldername;
        tempFolders[folderQuantity].parentFolder = this;

        for (unsigned int i = 0; i < folderQuantity; i++)
        {
            tempFolders[i] = folders[i];
        }

        delete[] folders;

        folders = tempFolders;

        folderQuantity++;

        return true;
    }

    cout << "Error: This exceeds the limit of max allowed folders\n";

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

    cout << "Error: This exceeds the limit of max allowed files\n";

    return false;
}

void Folder::PrintList()
{
    cout << "name" << "\t" << "size" << "\t" << "creation" << endl;

    for (unsigned int i = 0; i < folderQuantity; i++)
    {
        cout << "- " << folders[i].name << "\t" << folders[i].GetSizeInMB() << "\t" <<
                folders[i].dateOfCreation << "\n";
    }

    for (unsigned int i = 0; i < fileQuantity; i++)
    {
        cout << files[i].name << "\t" << files[i].sizeInMB << "\t" <<
                files[i].dateOfCreation << "\n";
    }
}

void Folder::PrintRecursive(Folder *ptr)
{
    if (ptr == NULL)
        return;

    PrintRecursive(ptr->parentFolder);

    cout << ptr->name << "/";
}

void Folder::PrintWorkingDirectory()
{
    PrintRecursive(this);
}

void Folder::PrintLargestFileInfo()
{
    File largest;
    largest.sizeInMB = -1;

    for (unsigned int i = 0; i < fileQuantity; i++)
    {
        if (files[i].sizeInMB > largest.sizeInMB)
        {
            largest = files[i];
        }
    }

    if (largest.sizeInMB > 0)
    {
        cout << largest.name << "\t" << largest.sizeInMB << "\t" <<
                largest.dateOfCreation << "\n";
    }
}

int Folder::GetSizeInMB()
{
    int filesize = 0;

    for (unsigned int i = 0; i < fileQuantity; i++)
    {
        filesize += files[i].sizeInMB;
    }

    if (folderQuantity != 0)
    {
        for (unsigned int i = 0; i < folderQuantity; i++)
        {
            filesize += folders[i].GetSizeInMB();
        }
    }

    return filesize;
}

Folder* Folder::GetFolder(string foldername)
{
    if  (foldername == "..")
    {
        if (parentFolder != NULL)
        {
            return parentFolder;
        }
    }

    for (unsigned int i = 0; i < folderQuantity; i++)
    {
        if (folders[i].name == foldername)
        {
            return &folders[i];
        }
    }

    cout << "Error: no such folder\n";

    return this;
}
