#ifndef PRINCIPIA_H
#define PRINCIPIA_H

#include <string>

class Principia
{
private:
    int sum;

public:
    struct Result
    {
        int Sn;
        int En;
    };

    static Result Sin(int n, int x);
    static Result Cos(int n, int x);
    static Result E(int n, int x);
    Principia();
};

#endif // PRINCIPIA_H
