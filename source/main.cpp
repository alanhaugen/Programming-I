#include "main.h"

/*! \mainpage Programming I: Compulsory 3
 *
 * \section intro_sec Introduction
 *
 * This Compulsory will cover elements such as use of pointers,
 * classes and objects (Object Oriented Programming).
 *
 * \section desc_sec Description
 *
 * We want to model the archive system of a computer.
 * This will have two types of elements: Folder and File,
 * which will have different types of properties.
 * Specifically, they will both have a name, size, and date of creation.
 * On the other hand, Folder will also have an array of maximum 10 Files,
 * and an array of maximum 5 Folders. We need operations to create new
 * Files and new Folders, with a random size of maximum 100 MB
 * (just generate a number between 0 and 100 for this). We also
 * want to know the names, sizes, and dates of creation, as well
 * as operations to change the name of the Files and Folders. We
 * finally want to be able to print all the information of a given
 * File or Folder (in the case of Folders, that includes printing all
 * Files within it).
 *
 * \section Instructions
 *
 * In the main program, we want to be able to create all of these types
 * of objects, and we also want to look through the Files in a given folder
 * and return the information (name, size, date of creation) of the largest
 * File. For these, the user needs to specify the name of the Folder they want
 * to look through for both of these operations. Create in the main one Folder
 * that will hold all this information.
 *
 * \section Submission
 *
 * The submission should be in the format Surname_Name_Compulsory3 on Canvas.
 * Clean code and XML comments are strongly encouraged. The file should be a
 * PDF file including the following:
 *
 * Link to the GitHub repository (public!) with the code and project files.
 * Implementation UML diagrams for the classes you have used
 * A brief paragraph describing where you feel you are with programming,
 * what do you feel most comfortable doing from what you\'ve learned this year,
 * and what you feel you need to improve on the most from what you've learned
 * this year.
 *
*/

#include "folder.h"
#include "file.h"

void Help()
{
    cout << "Type ls to list files, pwd to print working directory,\n"
            "cd to change directory, touch to make a new file, mkdir\n"
            "to make a new directory. Type help to get this message\n"
            "again. Type sort to get info on the largest file in folder."
            "Type quit to quit.\n\n";
}

/// The main entry point of the program
int main()
{
    Folder root("/");
    Folder *activeFolder = &root;

    cout << "Alux user interface\n\n";

    Help();

    bool isAlive = true;
    string input;

    while (isAlive)
    {
        activeFolder->PrintWorkingDirectory();
        cout << "$ ";
        cin >> input;

        if (input == "ls")
        {
            activeFolder->PrintList();
        }
        else if (input == "pwd")
        {
            activeFolder->PrintWorkingDirectory();
            cout <<  endl;
        }
        else if (input == "touch")
        {
            cout << "Type name of file: ";
            cin >> input;
            activeFolder->AddFile(input);
        }
        else if (input == "mkdir")
        {
            cout << "Type name of folder: ";
            cin >> input;
            activeFolder->AddFolder(input);
        }
        else if (input == "cd")
        {
            cout << "Type name of folder (type .. to go up a folder): ";
            cin >> input;
            activeFolder = activeFolder->GetFolder(input);
        }
        else if (input == "quit")
        {
            isAlive = false;
        }
        else if (input == "sort")
        {
            activeFolder->PrintLargestFileInfo();
        }
        else if (input == "help")
        {
            Help();
        }
        else
        {
            cout << input << ": command not found\n";
        }
    }

    return 0;
}
