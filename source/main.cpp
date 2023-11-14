#include <math.h>
#include "main.h"
#include "inputfunctions.h"
#include "polynomial.h"
#include "principia.h"

void a()
{
    cout << "{ 2n - 1} from n=1 to infinity" << endl;

    for (int n = 1; n <= 20; n++)
    {
        cout << "n = " << n << ": " << (2 * n) - 1 << endl;
    }
}

void b()
{
    cout << "{ ((-1)^(n+1)) * (1/n) } from n=1 to infinity" << endl;

    for (int n = 1; n <= 20; n++)
    {
        cout << "n = " << n << ": " << pow(-1, n+1) * (1/n) << endl;
    }
}

void c()
{
    cout << "{ 1/n! } from n=1 to infinity" << endl;

    for (int n = 1; n <= 20; n++)
    {
        cout << "n = " << n << ": " << 1 / Factorial(n) << endl;
    }
}

void one()
{
    a();
    b();
    c();
}

int main()
{
    /*
     * Programmering av matematikk i Programmering I tir 14.11 og tir 21.11 Høsten 2023
     * Du skal programmere matematikk i C++. Bruk gjerne en konsolapplikasjon, det
     * duger til de fleste oppgavene.
     *
     * Du trenger ikke ta oppgavene i rekkefølge, men de to første er nok de enkleste.
     *
     * - Oppgave 1
     *
     * Lag et program som beregn og skriv ut de 20 første leddene i disse følgene
     *
    */

    one();

    //while(true)
    //Principia princ;

    return 0;
}
