#include "principia.h"
#include "calc.h"

// todo: remove
#include "inputfunctions.h"
#include "polynomial.h"

/*int main() {
    while (yylex());
    return 0;
}*/

enum yytokentype {
    NUMBER = 258,
    ADD    = 259,
    SUB    = 260,
    MUL    = 261,
    DIV    = 262,
    ABS    = 263,
    EOL    = 264
};

extern int yylval;

Principia::Principia()
{
    sum = 0;

    bool isAdd = true;
    bool isSub = false;
    bool isDiv = false;
    bool isMul = false;

    // Take string and tokenize it
    int tok;

    bool isAlive = true;

    while (isAlive)
    {
        tok = yylex();

        //printf("%d", tok);

        switch(tok)
        {
        case NUMBER:
            if (isAdd)
            {
                sum += yylval;
            }
            else if (isSub)
            {
                sum -= yylval;
            }
            else if (isDiv)
            {
                sum /= yylval;
            }
            else if (isMul)
            {
                sum *= yylval;
            }
            break;

        case ADD:
            isAdd = true;
            isSub = false;
            isDiv = false;
            isMul = false;
            break;

        case SUB:
            isAdd = false;
            isSub = true;
            isDiv = false;
            isMul = false;
            break;

        case DIV:
            isAdd = false;
            isSub = false;
            isDiv = true;
            isMul = false;
            break;

        case MUL:
            isAdd = false;
            isSub = false;
            isDiv = false;
            isMul = true;
            break;

        case EOL:
            isAlive = false;

        default:
            printf("\n");
        }
    }

    printf("%i\n", sum);

    // flex and yacc galore
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
