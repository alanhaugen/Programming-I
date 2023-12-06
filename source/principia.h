#ifndef PRINCIPIA_H
#define PRINCIPIA_H

#include <string>

unsigned int Factorial(unsigned int n);

class Principia
{
private:
    int sum;
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
    };

    Principia();
    Principia(std::string sentence);

    double Sn;
    double En;

    Principia operator+(Principia const& obj)
    {
        return obj;
    }

    static Result Sin(int n, double x);
    static Result Cos(int n, double x);
    static Result E(int n, double x);
};

#endif // PRINCIPIA_H
