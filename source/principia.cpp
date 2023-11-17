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

Principia::Result Principia::Sin(int n, int x)
{
    Result a;
    a.En = n;
    a.Sn = x;

    return a;
}

Principia::Result Principia::Cos(int n, int x)
{
    Result a;
    a.En = n;
    a.Sn = x;

    return a;
}

Principia::Result Principia::E(int n, int x)
{
    Result a;
    a.En = n;
    a.Sn = x;

    return a;
}

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
