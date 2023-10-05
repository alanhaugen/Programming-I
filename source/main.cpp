#include "main.h"
#include "inputfunctions.h"
#include "polynomial.h"

#ifdef PRINCIPIA
#include "principia.h"
Principia princ;
#endif

/*! \mainpage Programming I: Compulsory 2
 *
 * \section intro_sec Introduction
 *
 * This Compulsory will cover elements such as use of pointers, classes and objects (Object Oriented Programming).
 * 
 * \section desc_sec Description
 *
 * We want to model the archive system of a computer. This will have two types of elements: Folder and File, which will have different types of properties. Specifically, they will both have a name, size, and date of creation. On the other hand, Folder will also have an array of maximum 10 Files, and an array of maximum 5 Folders. We need operations to create new Files and new Folders, with a random size of maximum 100 MB (just generate a number between 0 and 100 for this). We also want to know the names, sizes, and dates of creation, as well as operations to change the name of the Files and Folders. We finally want to be able to print all the information of a given File or Folder (in the case of Folders, that includes printing all Files within it).
 * 
 * \section Instructions
 *
 * In the main program, we want to be able to create all of these types of objects, and we also want to look through the Files in a given folder and return the information (name, size, date of creation) of the largest File. For these, the user needs to specify the name of the Folder they want to look through for both of these operations. Create in the main one Folder that will hold all this information.
 *
 * \section Submission
 * 
 * The submission should be in the format Surname_Name_Compulsory3 on Canvas. Clean code and XML comments are strongly encouraged. The file should be a PDF file including the following:
 * 
 * Link to the GitHub repository (public!) with the code and project files.
 * Implementation UML diagrams for the classes you have used
 * A brief paragraph describing where you feel you are with programming, what do you feel most comfortable doing from what you\'ve learned this year, and what you feel you need to improve on the most from what you've learned this year.
 *
 *
*/

/// The main entry point of the program
int main()
{
    bool isAlive = true;

    cout << "Alan's Calculator" << endl << endl;

    while (isAlive)
    {
        cout << "Choose one of the following options:" << endl << endl;

        cout << "[1] Calculate factorial" << endl;
        cout << "[2] Solve polynomial" << endl;
        cout << "[3] Solve simple math equations (simple sums and divisions)" << endl;
        cout << "[4] Quit program" << endl;

        int input = GetInteger();

        switch (input)
        {
        case 1:
            cout << Factorial(GetUnsignedInteger("Choose n (n!): ")) << endl; // 20 is limit
            break;

        case 2:
            SolvePolynomial();
            break;

        case 3:
            Calc();
            break;

        case 4:
            isAlive = false;
            break;

#ifdef PRINCIPIA
        case 5:
            princ = Principia(GetString("You found a secret,\nType an expression: \n\n"));
            break;
#endif

        default:
            cout << "Error: That is not one of the available options. Try again..." << endl;
            break;
        }
    }

    return 0;
}

/// Calculate factorial (n!) recursively
///
/// This function will only accept positive numbers and will output an error
/// if n > 20 since factorials of this size are outside the range of unsigned long long int
unsigned long long int Factorial(unsigned int n)
{
    if (n > 20)
    {
        cout << "Error! n must below 20!" << endl
             << "This is because 21! is above unsigned long long int resolution (2^64 - 1)"
             << endl;

        return 0;
    }

    if (n > 1)
    {
        return n * Factorial(n-1);
    }

    return 1;
}

/// Function which allows user to put in two polynomials
/// and do addition, substraction, multiplication and division
void SolvePolynomial()
{
    Polynomial a(GetInteger("Insert coefficiant for x^3: "),
                 GetInteger("Insert coefficiant for x^2: "),
                 GetInteger("Insert coefficiant for x^1: "),
                 GetInteger("Insert constant: "));

    if (a.isSolved)
    {
        cout << "Solutions (f(x) = 0): ";

        // Go through all solutions and output them
        cout << endl << a.solutions[0] << endl;

        if (a.isTwoSolutions)
        {
            cout << a.solutions[1] << endl;
        }
    }

    cout << "Please choose another polynomial" << endl;

    Polynomial b(GetInteger("Insert coefficiant for x^3: "),
                 GetInteger("Insert coefficiant for x^2: "),
                 GetInteger("Insert coefficiant for x^1: "),
                 GetInteger("Insert constant: "));

    string operation = GetString("Choose operation (+ - *): "); // /

    switch(operation[0])
    {
    case '+':
        (a + b).Print();
        break;
    case '-':
        (a - b).Print();
        break;
    case '*':
        (a * b).Print();
        break;
    /*case '/':
        (a / b).Print();
        break;*/
    default:
        cout << "Illegal operation" << endl;
        break;
    }
}

/// Do basic calculations
void Calc()
{
    double a = GetDouble("Choose a number: ");
    string operation = GetString("Choose operation (+ - * /): ");
    double b = GetDouble("Choose another number: ");

    switch(operation[0])
    {
    case '+':
        cout << a + b;
        break;
    case '-':
        cout << a - b;
        break;
    case '*':
        cout << a * b;
        break;
    case '/':
        cout << a / b;
        break;
    default:
        cout << "Illegal operation" << endl;
        break;
    }

    cout << endl;
}
