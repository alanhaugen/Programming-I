#ifndef PRINCIPIA_H
#define PRINCIPIA_H

#include <string>

unsigned int Factorial(unsigned int n);

class Principia
{
private:
    int sum;

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
    };

    static Result Sin(int n, double x);
    static Result Cos(int n, double x);
    static Result E(int n, double x);

    Principia();
};

#endif // PRINCIPIA_H
