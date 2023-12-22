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
    a.En = n;
    a.Sn = x;

    return a;
}

void Principia::Parse(std::string sentence = "")
{
    sum = 0.0f;

    bool isAdd = true;
    bool isSub = false;
    bool isDiv = false;
    bool isMul = false;

    // Parameter mode
    bool isParam = false;
    float param = 0.0f;

    // States for sin and cos
    bool isSin = false;
    bool isCos = false;

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

    while (isAlive)
    {
        tok = yylex();

        //printf("%d", tok);

        switch(tok)
        {
        case NUMBER:
            if (isParam == false)
            {
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
            }
            else
            {
                param = yylval;
                printf("n=%f\n", param);
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

        case SIN:
            isSin = true;
            break;
        case COS:
            isCos = true;
            break;
        case COMMA:
            //printf("comma\n");
            break;
        case PI:
            sum += 3.14156f;
            break;

        case LEFT_PAR:
            //printf("Left parenthesis\n");
            break;
        case RIGHT_PAR:
            //printf("Right parenthesis\n");
            break;

        case PARAMETER:
            isParam = true;
            //printf("Parameter\n");
            break;

        case E_POW:
            printf("E to the power of\n");
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

    printf("x=%f\n", sum);

    if (isSin && isCos)
    {
        Result a = Sin(param, sum) + Cos(param,sum);

        printf("\nSn = %f\n", a.Sn);
        printf("En = %f\n\n", a.En);
    }
    else if (isSin)
    {
        Result a = Sin(param, sum);

        printf("\nSn = %f\n", a.Sn);
        printf("En = %f\n\n", a.En);
    }
    else if (isCos)
    {
        Result a = Cos(param, sum);

        printf("\nSn = %f\n", a.Sn);
        printf("En = %f\n\n", a.En);
    }
}

Principia::Principia()
{
    Parse();
}

Principia::Principia(std::string sentence)
{
    Parse(sentence);
}
