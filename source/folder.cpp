#include "folder.h"
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <chrono>

using namespace std;

/// Init function
///
/// This is called in the constructors to avoid code duplication
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

/// Folder default constructor
///
/// This is called when a new file is created
Folder::Folder()
{
    Init();
}

/// Folder constructor
///
/// This is called when a new file is created with a name
Folder::Folder(string _name)
{
    name = _name;

    Init();
}

/// Folder destructor
///
/// This is called when a file deleted with delete
Folder::~Folder()
{
    delete[] folders;
}

/// Add folder method for folder
///
/// This is used to add folders to a folder
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

/// Add file method for folder
///
/// This is used to add files to a folder
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

/// Move file or folder method for folder
///
/// This is used to move filels and folders in a folder
bool Folder::MoveFileOrFolder(string filename, string newname)
{
    for (unsigned int i = 0; i < folderQuantity; i++)
    {
        if (folders[i].name == filename)
        {
            folders[i].name = newname;
            return true;
        }
    }

    for (unsigned int i = 0; i < fileQuantity; i++)
    {
        if (files[i].name == filename)
        {
            files[i].name = newname;
            return true;
        }
    }

    return false;
}

/// Print List
///
/// This will cout (print) all pf the folders and files in a folder.
/// Folders will have a minus (- ) preceding it's output
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

/// Print Recursive helper method
///
/// This is a helper method for PrintWorkingDirectory
/// The function is recursive and is used to work where
/// the folder is in the file hierarchy
void Folder::PrintRecursive(Folder *ptr)
{
    if (ptr == NULL)
        return;

    PrintRecursive(ptr->parentFolder);

    cout << ptr->name << "/";
}

/// Print Working Directory method
///
/// Prints where the folder is in the file hierarchy
void Folder::PrintWorkingDirectory()
{
    PrintRecursive(this);
}

/// Print Largest File Info
///
/// Prints largest file in folder
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

/// Get Size In MB
///
/// This method is used to find filesize of all the files
/// in a folder
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

/// Get Folder methid
///
/// This method is used get a pointer to a folder
/// The folder has to exist in the current folder.
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
