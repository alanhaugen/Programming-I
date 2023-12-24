#include <math.h>
#include <iostream>
#include "principia.h"
#include "calc.h"

/*int main() {
    while (yylex());
    return 0;
}*/

unsigned int Factorial(unsigned int n)
{
    int result = 1;

    for (unsigned int i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

double Calculation(double sum, double value, int currentOperation)
{
    switch (currentOperation)
    {
    case ADDITION:
        return sum += value;
    case SUBTRACTION:
        return sum -= value;
    case MULTIPLICATION:
        return sum *= value;
    case DIVISION:
        return sum /= value;
    }

    return 0;
}

Principia::Result Principia::Sin(int n, double x)
{
    Result a;

    for (int i = 0; i < n; i++)
    {
        double fortegn = pow(-1, i);
        double nevner  = Factorial((2 * i) + 1);
        double xn  = pow(x, (2 * i) + 1);
        a.Sn += (fortegn / nevner) * xn;
    }

    a.En = pow(x, 2 * (n + 1) + 1) / Factorial(2 * (n+1)+1);
    if (a.En < 0.) a.En = -a.En;

    return a;
}

Principia::Result Principia::Cos(int n, double x)
{
    Result a;

    for (int i = 0; i < n; i++)
    {
        double fortegn = pow(-1, i);
        double nevner  = Factorial(2 * i);
        double xn  = pow(x, 2 * i);
        a.Sn += (fortegn / nevner) * xn;
    }

    a.En = pow(x, 2 * (n + 1) + 1) / Factorial(2 * (n+1)+1);
    if (a.En < 0.) a.En = -a.En;

    return a;
}

Principia::Result Principia::E(int n, double x)
{
    Result a;

    for (int i = 0; i < n; i++)
    {
        double teller = pow(x, i);
        double nevner  = Factorial(i);
        a.Sn += teller / nevner;
    }

    a.En = pow(x, 2 * (n + 1) + 1) / Factorial(2 * (n+1)+1);
    if (a.En < 0.) a.En = -a.En;

    return a;
}

void Principia::Parse(std::string sentence = "")
{
    // Parameter mode
    bool isParam = false;
    float param = 0.0f;

    // Second parameter mode
    bool isSecondParam = false;
    float secondParam = 0.0f;

    // State for sequences
    bool isSequence = false;
    bool isSum      = false;

    // States for sin and cos and E^
    bool isSin  = false;
    bool isCos  = false;
    bool isPowE = false;

    // Take string and tokenize it
    int tok;

    // Store string buffer for string input
    YY_BUFFER_STATE buffer;
    bool isStringInput = false;

    if (sentence.empty() == false)
    {
        printf("%s\n", sentence.c_str()); // Output input string
        sentence += "\n\0\0"; // Lex wants strings to end with double null characters

        buffer = yy_scan_string(const_cast<char *>(sentence.c_str()));
        isStringInput = true;
    }

    bool isAlive = true;

    Expression expression;

    while (isAlive)
    {
        tok = yylex();

        switch(tok)
        {
        case NUMBER:
            if (isParam == false)
            {
                expression.AddSymbol(QUANTITY, yylval);
            }
            else
            {
                if (isSecondParam == false)
                {
                    param = yylval;
                    isSecondParam = true;
                }
                else
                {
                    secondParam = yylval;
                }
            }
            break;

        case ADD:
            expression.AddSymbol(ADDITION);
            break;

        case SUB:
            expression.AddSymbol(SUBTRACTION);
            break;

        case DIV:
            expression.AddSymbol(DIVISION);
            break;

        case MUL:
            expression.AddSymbol(MULTIPLICATION);
            break;

        case SIN:
            isSin = true;
            break;

        case COS:
            isCos = true;
            break;

        case PI:
            expression.AddSymbol(QUANTITY, 3.141593);
            break;

        case LEFT_PAR:
            break;

        case RIGHT_PAR:
            break;

        case LEFT_CURL:
            isSequence = true;
            break;

        case RIGHT_CURL:
            break;

        case PARAMETER:
            isParam = true;
            break;

        case E_POW:
            isPowE = true;
            break;

        case VAR:
            expression.AddSymbol(VARIABLE);
            break;

        case SQRT:
            expression.AddSymbol(SQUARE_ROOT);
            break;

        case FACTORIAL:
            expression.symbols.back().isFactorial = true;
            break;

        case SUM:
            isSum = true;
            break;

        case IGNORE:
            break;

        case EOL:
            isAlive = false;
            break;

        default:
            printf("\n");
        }
    }

    if (isStringInput)
    {
        yy_delete_buffer(buffer);
    }

    if (isSin && isCos)
    {
        Result a = Sin(param, expression.Compute()) + Cos(param, expression.Compute());

        printf("Sn = %f\n", a.Sn);
        printf("En = %f", a.En);
    }
    else if (isSin)
    {
        Result a = Sin(param, expression.Compute());

        printf("Sn = %f\n", a.Sn);
        printf("En = %f", a.En);
    }
    else if (isCos)
    {
        Result a = Cos(param, expression.Compute());

        printf("Sn = %f\n", a.Sn);
        printf("En = %f", a.En);
    }
    else if (isPowE)
    {
        Result a = E(param, expression.Compute());

        printf("Sn = %f\n", a.Sn);
        printf("En = %f", a.En);
    }
    else if (isSequence)
    {
        printf("{ ");

        double sum = 0.0f;

        for (long int i = param; i <= secondParam; i++)
        {
            if (i != secondParam)
            {
                printf("%.3f, ", expression.Compute(i));
            }
            else
            {
                printf("%.3f", expression.Compute(i));
            }

            sum += expression.Compute(i);
        }

        printf(" }");

        if (isSum)
        {
            printf("\nSum: %f", sum);
        }
    }
    else
    {
        printf("%.3f", expression.Compute());
    }

    printf("\n\n");
}

Principia::Principia()
{
    Parse();
}

Principia::Principia(std::string sentence)
{
    Parse(sentence);
}
