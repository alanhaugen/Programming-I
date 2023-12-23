#ifndef PRINCIPIA_H
#define PRINCIPIA_H

#include <string>
#include <vector>

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
    PI,
    LEFT_PAR,
    RIGHT_PAR,
    LEFT_CURL,
    RIGHT_CURL,
    PARAMETER,
    E_POW,
    IGNORE,
    VAR,
    EOL
};

extern double yylval;

class Principia
{
private:
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

    enum type
    {
        QUANTITY,
        VARIABLE,
        ADDITION, // Operators
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION,
        EXPONENTIATION
    };

    struct Expression
    {
        struct Symbol
        {
            int type;
            double value;

            Symbol(int type_ = QUANTITY, double value_ = 1.0f)
            {
                type  = type_;
                value = value_;
            }
        };

        std::vector<Symbol> symbols;
        int currentOperation;

        Expression()
        {
        }

        double Compute(long int variable = 1)
        {
            double sum = 0.0f;
            currentOperation = ADDITION;

            for (unsigned long i = 0; i < symbols.size(); i++)
            {
                switch (symbols[i].type)
                {
                case QUANTITY:
                    switch (currentOperation)
                    {
                    case ADDITION:
                        sum += symbols[i].value;
                        break;
                    case SUBTRACTION:
                        sum -= symbols[i].value;
                        break;
                    case MULTIPLICATION:
                        sum *= symbols[i].value;
                        break;
                    case DIVISION:
                        sum /= symbols[i].value;
                        break;
                    }
                    break;
                case VARIABLE:
                    sum *= variable; // add division
                    break;
                case ADDITION:
                    currentOperation = ADDITION;
                    break;
                case SUBTRACTION:
                    currentOperation = SUBTRACTION;
                    break;
                case MULTIPLICATION:
                    currentOperation = MULTIPLICATION;
                    break;
                case DIVISION:
                    currentOperation = DIVISION;
                    break;
                case EXPONENTIATION:
                    break;
                }
            }

            return sum;
        }

        void AddSymbol(int type, double value = 0.0f)
        {
            if (symbols.empty() && type != QUANTITY)
            {
                symbols.push_back(Symbol(QUANTITY, 1.0f));;
            }

            symbols.push_back(Symbol(type, value));
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
