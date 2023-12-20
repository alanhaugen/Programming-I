%option noyywrap

/* recognize tokens for the calculator and print them out */

%{
    enum yytokentype {
        NUMBER = 258,
        ADD,
        SUB,
        MUL,
        DIV,
        ABS,
        SIN,
        COS,
        COMMA,
        PI,
        LEFT_PAR,
        RIGHT_PAR,
        PARAMETER,
        EOL
    };

    double yylval;
%}

%%

"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"|" { return ABS; }
"sin" { return SIN; }
"sinus" { return SIN; }
"cos" { return COS; }
"cosinus" { return COS; }
"," { return COMMA; }
"(" { return LEFT_PAR; }
")" { return RIGHT_PAR; }
"pi" { return PI; }
"n=" { return PARAMETER; }
[0-9]+(\.[0-9]+)? { yylval = atof(yytext); return NUMBER; }
\n { return EOL; }
[ \t] { /* ignore whitespace */ }
. { printf("Mystery character %s\n", yytext); }

%%

/*int main() {
    while (yylex());
    return 0;
}*/

