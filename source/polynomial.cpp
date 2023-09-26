#include "polynomial.h"
#include <cmath>

#include <iostream>

using namespace std;

/// Default constructer: Creates a polynomial with all attributes set to 0
Polynomial::Polynomial()
{
    Init();
}

/// Constructor: Creates a polynomial where you can decide on some attributes
Polynomial::Polynomial(double third, double second, double first, double c)
{
    Init();

    coefficiants[3] = third;
    coefficiants[2] = second;
    coefficiants[1] = first;
    *constant = c;

    isSolved = false;

    Solve();
}

/// Will print out the derivation of the polynomial
void Polynomial::Derivate()
{
    for (int i = MAX_COEFFCIANTS - 1; i >= 0; i--)
    {
        cout << coefficiants[i] * i << " x^" << i-1 << " + ";
    }

    cout << coefficiants[1];

    cout << endl;
}

/// Prints out some of the attributes of the polynomial
void Polynomial::Print()
{
    for (int i = MAX_COEFFCIANTS - 1; i >= 0; i--)
    {
        if (coefficiants[i] != 0)
        {
            cout << coefficiants[i];

            if (i != 0)
            {
                cout << " x^" << i << " + ";
            }
        }
    }

    cout << endl;
}

/// Doc
void Polynomial::Solve()
{
    double thirdDegreeCoefficiants  = coefficiants[3];
    double secondDegreeCoefficiants = coefficiants[2];
    double firstDegreeCoefficiants  = coefficiants[1];
    double constant = coefficiants[0];

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

/// Initialise the object
void Polynomial::Init()
{
    for (int i = 0; i < MAX_COEFFCIANTS; i++)
    {
        coefficiants[i] = 0;
    }

    constant = &coefficiants[0];

    isSolved = false;
}
