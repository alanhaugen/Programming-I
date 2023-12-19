#include <math.h>
#include "main.h"
#include "inputfunctions.h"
#include "polynomial.h"
#include "principia.h"
#include <vector>

void a1()
{
    cout << "{ 2n - 1 } from n=1 to infinity" << endl;
    cout << "This sequence is the odd numbers" << endl;

    for (int n = 1; n <= 20; n++)
    {
        cout << "n = " << n << ": " << (2 * n) - 1 << endl;
    }
}

void b1()
{
    cout << "{ ((-1)^(n+1)) * (1/n) } from n=1 to infinity" << endl;

    for (int n = 1; n <= 20; n++)
    {
        cout << "n = " << n << ": " << pow(-1, n+1) * (1/double(n)) << endl;
    }
}

void c1()
{
    cout << "{ 1/n! } from n=1 to infinity" << endl;

    for (int n = 1; n <= 20; n++)
    {
        cout << "n = " << n << ": " << double(1) / Factorial(n) << endl;
    }
}

void d1()
{
    cout << "{ ((-1)^(n+1)) / (1/n!) } from n=1 to infinity" << endl;

    for (int n = 1; n <= 20; n++)
    {
        cout << "n = " << n << ": " << double(1) / Factorial(n) << endl;
    }
}

void e1()
{
    cout << "{ sinus ((n * pi) / 2) } from n=1 to infinity" << endl;

    for (int n = 1; n <= 20; n++)
    {
        cout << "n = " << n << ": " << sin((double(n) * M_PI) / double(2)) << endl;
    }
}

void fibonacci()
{
    int previousResult1 = 1;
    int previousResult2 = 1;

    cout << "The fibonacci sequence. This sequence is recursive" << endl;
    for (int n = 1; n <= 20; n++)
    {
        cout << previousResult1 + previousResult2 << endl;
        int temp = previousResult1 + previousResult2; // temp variable is vital
        previousResult1 = previousResult2;
        previousResult2 = temp;
    }
}

void one()
{
    /*
     * - Oppgave 1
     *
     * Lag et program som beregn og skriv ut de 20 første leddene i disse følgene
     *
    */

    a1();
    b1();
    c1();
    d1();
    e1();
    fibonacci();
}

void a2()
{
    cout << "{(i*i - 4)} from i=1 to 20" << endl;

    double sum = 0;

    for (int i = 1; i <= 20; i++)
    {
        cout << "i = " << i << ": " << (i*i - 4) << endl;
        sum += (i*i - 4);
    }

    cout << "Sum: " << sum << endl;
}

void b2()
{
    cout << "{sin(i/10)} from i=0 to 32" << endl;

    double sum = 0;

    for (int i = 0; i <= 32; i++)
    {
        cout << "i = " << i << ": " << (sin(i/double(10))) << endl;
        sum += (sin(i/double(10)));
    }

    cout << "Sum: " << sum << endl;
}

void c2()
{
    cout << "{sqrt(4*i)} from i=0 to 16" << endl;

    double sum = 0;

    for (int i = 0; i <= 16; i++)
    {
        cout << "i = " << i << ": " << (sqrt(4*i)) << endl;
        sum += (sqrt(4*i));
    }

    cout << "Sum: " << sum << endl;
}

void two()
{
    /*
     * - Oppgave 2
     *
     * Lag et program som skriver ut alle leddene OG summen
     *
    */

    a2();
    b2();
    c2();
}

void a3()
{
    // Lag en funksjon for sin(x) med input parametre n og x, som returnerer Sn og |En|.
    int n = 7;
    double x = M_PI / 4;

    Principia::Result p = Principia::Sin(n, x);

    cout << "Sn: " << p.Sn << endl;
    cout << "En: " << p.En << endl;
}

void b3()
{
    // Lag en funksjon for cos(x) med input parametre n og x, som returnerer Sn og |En|.
    int n = 7;
    double x = M_PI / 4;

    Principia::Result p = Principia::Cos(n, x);

    cout << "Sn: " << p.Sn << endl;
    cout << "En: " << p.En << endl;
}

void c3()
{
    // Lag en funksjon for e^x med input parametre n og x, som returnerer Sn og |En|.
    int n = 1;
    double x = 1.0;

    Principia::Result p = Principia::E(n, x);

    cout << "Sn: " << p.Sn << endl;
    cout << "En: " << p.En << endl;
}

void d3()
{
    // Lag en funksjon som beregner sin(x) + cos(x) med input parametre n og x,
    // som returnerer Sn og |En|.
    int n = 7;
    double x = M_PI / 4;

    Principia p = Principia("sin " + to_string(n) + "," + to_string(x))
                + Principia("cos " + to_string(n) + "," + to_string(x));

    cout << "Sn: " << p.Sn << endl;
    cout << "En: " << p.En << endl;
}

void e3()
{
    // Lag en funksjon som beregner sin(x) + cos(x) med input parametre n og x,
    // som returnerer Sn og |En|.
}

void three()
{
    /*
     * - Oppgave 3
     *
     * Du skal programmere kjente funksjoner ved å bruke potensrekka for
     * disse funksjonene, med sentrum i 0, dvs. a=0. Da kalles det
     * Maclaurin rekka for de aktuelle funksjonene, disse står på side 351 i boka.
     *
    */

    //a3();
    //b3();
    //c3();
    d3();
    //e3();
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
    */

    //one();
    //two();

    three();

    //while(true)
    //Principia();

    return 0;
}
