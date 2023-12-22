#ifndef PRINCIPIA_H
#define PRINCIPIA_H

#include <string>

unsigned int Factorial(unsigned int n);

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
    E_POW,
    EOL
};

extern double yylval;

class Principia
{
private:
    double sum;
    void Parse(std::string sentence);

public:
    struct Result
    {
        double Sn;
        double En;

        Result()
        {
            Sn = 0;
            En = 0;
        }

        Result operator+(Result const& obj)
        {
            Sn += obj.Sn;
            En += obj.En;

            return *this;
        }
    };

    Principia();
    Principia(std::string sentence);

    double Sn;
    double En;

    static Result Sin(int n, double x);
    static Result Cos(int n, double x);
    static Result E(int n, double x);
};

#endif // PRINCIPIA_H
