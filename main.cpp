#include <iostream>
#include <string>

using namespace std;

/*
 * For this Compulsory, you will have to create a program using a
 * Procedural Programming Paradigm approach to implement a calculator
 * that will perform the following operations:

 * Factorial (use recursion)
 * Solving polynomial equations
 * Simple math equations (addition, subtraction, multiplication and division).

 * In order to do this, create a menu system that will allow the user to
 * choose between these three options, as well as offer a choice to terminate
 * the program. Use functions to keep the code as clear and modular as
 * possible. Control for unexpected inputs (strings where numbers are expected).
 * Use XML documentation practices for all defined functions. The submission
 * will be a PDF with Surname_Name_Compulsory2 and have the following:

 * Link to GitHub repository (public!) with all the project files and code
 * Brief paragraph discussing the benefits of using recursion in certain scenarios versus an iterative approach
 * How you feel you have progressed in programming since the start of the semester.
*/

int main()
{
    //Define an array of integers, ask the user for the size, and then for them to
    //fill out with numbers greater than zero. Controls for errors.
    int input;

    cout << "Please specify size of an array \n";

    cin >> input;

    int *arr = new int(input);

    // Print out the values of the array using a for loop
    for (int i = 0, size = input; i < size; i++)
    {
        cout << "Set a number greater than 0 (i>0) for array element #" << i << ": ";

        cin >> input;

        if (input < 0)
        {
            cout << "Please try again with a number greate than 0\n";
            i--;
            continue;
        }

        arr[i] = input;

        cout << "Element " << i << " is now " << arr[i] << "\n";
    }

    // Add a while loop and three different options for the user to do. Use
    //switch-case to create this menu
    do
    {
        cout << "\n\nPlease enter one of the following commands:\n\n";
        cout << "[1] Create array\n";
        cout << "[2] Print array\n";
        cout << "[3] Change value of X position of array\n";
        cout << "[4] Exit/Stop\n";

        cin >> input;

        switch(input)
        {
        case 1:
            // Create array
            break;
        case 2:
            // Print array
            break;
        case 3:
            // Change value of X position of array
            break;
        case 4:
            // Exit/Stop
            break;
        default:
            cout << "Please add one of the options.\n";
        }
    }
    while(input != 4);

    // What happens if we try to print an empty array? And if we try to change
    // the value of a position of an array with no values?
    int emptyArray[] = {};

    for (int i = 0; i < 100; i++)
    {
        cout << emptyArray[i];
        emptyArray[i] = i;
    }

    //Create a two-dimensional array (matrix) of 3x3, ask users to introduce
    //an X or an O. Check when there are 3 X’s or 3 O’s in the same row or
    //the same column
    // Extra: Check if it’s diagonal as well.


    return 0;
}
