#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
public:
    double thirdDegreeCoefficiants;
    double secondDegreeCoefficiants;
    double firstDegreeCoefficiants;
    double constant;

    void Derivate();
    void Print();

    Polynomial();
    Polynomial(double third, double second, double first, double c);

    Polynomial operator+(const Polynomial& rhs)
    {
        return Polynomial(thirdDegreeCoefficiants + rhs.thirdDegreeCoefficiants, secondDegreeCoefficiants + rhs.secondDegreeCoefficiants, firstDegreeCoefficiants + rhs.firstDegreeCoefficiants, constant + rhs.constant);
    }

    Polynomial operator-(const Polynomial& rhs)
    {
        return Polynomial(thirdDegreeCoefficiants - rhs.thirdDegreeCoefficiants, secondDegreeCoefficiants - rhs.secondDegreeCoefficiants, firstDegreeCoefficiants - rhs.firstDegreeCoefficiants, constant - rhs.constant);
    }

    Polynomial operator*(const Polynomial& rhs)
    {
        return Polynomial();
        //return Polynomial(thirdDegreeCoefficiants * rhs.thirdDegreeCoefficiants, secondDegreeCoefficiants * rhs.secondDegreeCoefficiants, firstDegreeCoefficiants * rhs.firstDegreeCoefficiants, constant * rhs.constant);
    }

    Polynomial operator/(const Polynomial& rhs)
    {
        return Polynomial();
        //return Polynomial(thirdDegreeCoefficiants / rhs.thirdDegreeCoefficiants, secondDegreeCoefficiants / rhs.secondDegreeCoefficiants, firstDegreeCoefficiants / rhs.firstDegreeCoefficiants, constant / rhs.constant);
    }
};

#endif // POLYNOMIAL_H
