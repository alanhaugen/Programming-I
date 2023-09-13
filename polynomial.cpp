#include "polynomial.h"
#include <cmath>

Polynomial::Polynomial()
{
    thirdDegreeCoefficiants  = 0;
    secondDegreeCoefficiants = 0;
    firstDegreeCoefficiants  = 0;
    constant = 0;

    isSolved = false;
}

Polynomial::Polynomial(double third, double second, double first, double c)
{
    thirdDegreeCoefficiants  = third;
    secondDegreeCoefficiants = second;
    firstDegreeCoefficiants  = first;
    constant = c;

    isSolved = false;

    Solve();
}

void Polynomial::Derivate()
{
    //cout << thirdDegreeCoefficiants * 3 << " x^2 + ";
    //cout << secondDegreeCoefficiants * 2 << " x + ";
    //cout << firstDegreeCoefficiants;

    //cout << endl;
}

void Polynomial::Print()
{
    //cout << thirdDegreeCoefficiants << " x^3 + ";
    //cout << secondDegreeCoefficiants << " x^2 + ";
    //cout << firstDegreeCoefficiants << " x + ";
    //cout << constant;

    //cout << endl;
}

void Polynomial::Solve()
{
    // Solve and find x = 0 (list)
    if (thirdDegreeCoefficiants == 0)
    {
        if (secondDegreeCoefficiants != 0)
        {
            // Second degree equation
            solutions[0] = -(firstDegreeCoefficiants + sqrt((firstDegreeCoefficiants * firstDegreeCoefficiants) - 4*secondDegreeCoefficiants*constant))/(2*secondDegreeCoefficiants);
            solutions[1] = -(firstDegreeCoefficiants - sqrt((firstDegreeCoefficiants * firstDegreeCoefficiants) - 4*secondDegreeCoefficiants*constant))/(2*secondDegreeCoefficiants);

            isSolved = true;
            isTwoSolutions = true;
        }
        else if (firstDegreeCoefficiants != 0)
        {
            // First degree equation
            solutions[0] = -constant / firstDegreeCoefficiants;

            isSolved = true;
            isTwoSolutions = false;
        }
    }
}
