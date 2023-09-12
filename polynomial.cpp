#include <iostream>
#include "polynomial.h"

using namespace std;

Polynomial::Polynomial()
{
    thirdDegreeCoefficiants  = 0;
    secondDegreeCoefficiants = 0;
    firstDegreeCoefficiants  = 0;
    constant = 0;
}

Polynomial::Polynomial(double third, double second, double first, double c)
{
    thirdDegreeCoefficiants  = third;
    secondDegreeCoefficiants = second;
    firstDegreeCoefficiants  = first;
    constant = c;
}

void Polynomial::Derivate()
{
    cout << thirdDegreeCoefficiants * 3 << " x^2 + ";
    cout << secondDegreeCoefficiants * 2 << " x + ";
    cout << firstDegreeCoefficiants;

    cout << endl;
}

void Polynomial::Print()
{
    cout << thirdDegreeCoefficiants << " x^3 + ";
    cout << secondDegreeCoefficiants << " x^2 + ";
    cout << firstDegreeCoefficiants << " x + ";
    cout << constant;

    cout << endl;
}
