#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

const int MAX_COEFFCIANTS = 7;

class Polynomial
{
private:
    void Solve();
    void Init();

public:
    double coefficiants[MAX_COEFFCIANTS];
    double *constant;

    void Derivate();
    void Print();

    double solutions[2];
    bool isTwoSolutions;
    bool isSolved;

    Polynomial();
    Polynomial(double third, double second, double first, double c);

    /// + operator overload. Add to polynomials
    Polynomial operator+(const Polynomial& rhs)
    {
        return Polynomial(coefficiants[3] + rhs.coefficiants[3], coefficiants[2] + rhs.coefficiants[2], coefficiants[1] + rhs.coefficiants[1], *constant + *rhs.constant);
    }

    /// - operator overlad. Substract to polynomials
    Polynomial operator-(const Polynomial& rhs)
    {
        return Polynomial(coefficiants[3] - rhs.coefficiants[3], coefficiants[2] - rhs.coefficiants[2], coefficiants[1] - rhs.coefficiants[1], *constant - *rhs.constant);
    }

    Polynomial operator*(const Polynomial& rhs)
    {
        Polynomial result;

        for (int i = 0; i < MAX_COEFFCIANTS; i++)
        {
            for (int j = 0; j < MAX_COEFFCIANTS; j++)
            {
                result.coefficiants[i+j] += coefficiants[i] * rhs.coefficiants[j];
            }
        }

        return result;
    }

    /*Polynomial operator/(const Polynomial& rhs)
    {
        Polynomial result;

        for (int i = 0; i < MAX_COEFFCIANTS; i++)
        {
            for (int j = 0; j < MAX_COEFFCIANTS; j++)
            {
                result.coefficiants[i] = coefficiants[i] / rhs.coefficiants[j];
            }
        }

        return result;
    }*/
};

#endif // POLYNOMIAL_H
