#include <math.h>
#include <iostream>
#include "principia.h"
#include "calc.h"

/*int main() {
    while (yylex());
    return 0;
}*/

enum yytokentype
{
    NUMBER = 258,
    ADD    = 259,
    SUB    = 260,
    MUL    = 261,
    DIV    = 262,
    ABS    = 263,
    EOL    = 264
};

extern int yylval;

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

    a.En = 0;

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

    a.En = n;

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
    sum = 0;

    bool isAdd = true;
    bool isSub = false;
    bool isDiv = false;
    bool isMul = false;

    // Take string and tokenize it
    int tok;

    // TODO: FIXME!
    if (sentence != "")
    {
        return;
    }

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
            break;

        default:
            printf("\n");
        }
    }

    printf("%i\n", sum);

    // flex and yacc galore
}

Principia::Principia()
{
    Parse();
}

Principia::Principia(std::string sentence)
{
    Parse(sentence);
}
