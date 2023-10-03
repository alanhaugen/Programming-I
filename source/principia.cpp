#include "principia.h"
#include "calc.h"

/*int main() {
    while (yylex());
    return 0;
}*/

Principia::Principia()
{
    // Take string and tokenize it
    while (yylex());
    // flex and yacc galore
}
