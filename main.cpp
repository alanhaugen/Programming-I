#include "main.h"
#include "inputfunctions.h"
#include "polynomial.h"

/*
 * For this Compulsory, you will have to create a program using a
 * Procedural Programming Paradigm approach to implement a calculator
 * that will perform the following operations:
 *
 * Factorial (use recursion)
 * Solving polynomial equations
 * Simple math equations (addition, subtraction, multiplication and division).
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

int main()
{
    bool isAlive = true;

    cout << "Alan's Calculator" << endl << endl; // Rom

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
            cout << Factorial(GetInteger("Choose n (n!): ")) << endl;
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

        case 5:
            princ = Principia(GetString("You found a secret,\nType an expression: \n\n"));
            break;

        default:
            cout << "Error: That is not one of the available options. Try again..." << endl;
            break;
        }
    }

    return 0;
}

unsigned int Factorial(unsigned int n)
{
    if (n > 1)
    {
        return n * Factorial(n-1);
    }

    return 1;
}

void SolvePolynomial()
{
    //GetString("Type a polynomial (ex. x^2 + 2x - 5): ");

    Polynomial a(0,
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
    else
    {
        cout << "Fail: No solutions calculated" << endl;
    }
}

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
