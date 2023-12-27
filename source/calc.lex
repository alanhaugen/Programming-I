%option noyywrap

/* recognize tokens for the calculator and print them out */

%{
    enum yytokentype {
        NUMBER = 258,
        ADD,
        SUB,
        MUL,
        DIV,
        EXP,
        ABS,
        SIN,
        COS,
        PI,
        SQRT,
        LEFT_PAR,
        RIGHT_PAR,
        LEFT_CURL,
        RIGHT_CURL,
        PARAMETER,
        E_POW,
        FACTORIAL,
        IGNORE,
        VAR,
        SUM,
        EOL
    };

    double yylval;
%}

%%

"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"^" { return EXP; }
"**" { return EXP; }
"|" { return ABS; }
"sin" { return SIN; }
"sinus" { return SIN; }
"cos" { return COS; }
"cosinus" { return COS; }
"(" { return LEFT_PAR; }
")" { return RIGHT_PAR; }
"{" { return LEFT_CURL; }
"}" { return RIGHT_CURL; }
"pi" { return PI; }
"n=" { return PARAMETER; }
"n" { return VAR; }
"x" { return VAR; }
"i" { return VAR; }
[0-9]+(\.[0-9]+)? { yylval = atof(yytext); return NUMBER; }
e^ { return E_POW; }
E^ { return E_POW; }
\n { return EOL; }
from { return IGNORE; }
to { return IGNORE; }
"," { return IGNORE; }
"sqrt" { return SQRT; }
"SQRT" { return SQRT; }
"sum" { return SUM; }
"include sum" { return SUM; }
"!" { return FACTORIAL; }
infinity { yylval = 20.0f; return NUMBER; }
[ \t] { /* ignore whitespace */ }
. { printf("Mystery character %s\n", yytext); }

%%

/*int main() {
    while (yylex());
    return 0;
}*/

