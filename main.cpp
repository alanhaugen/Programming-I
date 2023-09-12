#include "main.h"
#include "polynomial.h"

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
 * Brief paragraph discussing the benefits of using recursion in certain
 * scenarios versus an iterative approach.
 * How you feel you have progressed in programming since the start of the semester.
*/

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
            cout << endl << "Calculate factorial" << endl;
            cout << Factorial(GetInteger("Choose n (n!):")) << endl;
            break;

        case 2:
            cout << endl << "Solve polynomial" << endl;
            SolvePolynomial();
            break;

        case 3:
            cout << endl << "Simple math equations" << endl;
            Calc();
            break;

        case 4:
            isAlive = false;
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
    Polynomial a, b, result;

    a = Polynomial(GetInteger("Insert coefficiant for x^3: "),
                   GetInteger("Insert coefficiant for x^2: "),
                   GetInteger("Insert coefficiant for x^1: "),
                   GetInteger("Insert constant: "));

    string operation = GetString("Choose operation (+ - * /): ");

    cout << "Choose a second polynomial:" << endl;

    b = Polynomial(GetInteger("Insert coefficiant for x^3: "),
                   GetInteger("Insert coefficiant for x^2: "),
                   GetInteger("Insert coefficiant for x^1: "),
                   GetInteger("Insert constant: "));

    switch(operation[0])
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    default:
        cout << "Illegal operation" << endl;
        break;
    }

    result.Print();

    cout << "The derivative of first polynomial (a)" << endl;

    a.Derivate();
}

void Calc()
{
    double a = GetDouble("Choose a number: ");
    string operation = GetString("Choose operation (+ - * /): ");
    double b = GetDouble("Choose another a number: ");

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
