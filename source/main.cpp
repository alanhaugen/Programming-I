#include "main.h"
#include "inputfunctions.h"
#include "polynomial.h"

/*! \mainpage Programming I: Compulsory 2
 *
 * \section intro_sec Introduction
 *
 * For this Compulsory, you will have to create a program using a
 * Procedural Programming Paradigm approach to implement a calculator
 * that will perform the following operations:
 *
 * - Factorial (use recursion)
 * - Solving 3rd degree polynomial equations (addition, subtraction, multiplication)
 * - Simple math equations (addition, subtraction, multiplication and division).
 *
 * \section Instructions
 *
 * In order to do this, create a menu system that will allow the user to
 * choose between these three options, as well as offer a choice to terminate
 * the program. Use functions to keep the code as clear and modular as
 * possible. Control for unexpected inputs (strings where numbers are expected).
 * Use XML documentation practices for all defined functions. The submission
 * will be a PDF with Surname_Name_Compulsory2 and have the following:
 *
 * Link to GitHub repository (public!) with all the project files and code
 * Brief paragraph discussing the benefits of using recursion in certain
 * scenarios versus an iterative approach.
 * How you feel you have progressed in programming since the start of the semester.
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

        /*case 5:
            //princ = Principia(GetString("You found a secret,\nType an expression: \n\n"));
            break;*/

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
