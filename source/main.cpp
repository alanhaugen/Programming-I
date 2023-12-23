#include <math.h>
#include "main.h"
#include "inputfunctions.h"
#include "polynomial.h"
#include "principia.h"

void a1()
{
    cout << "This sequence is the odd numbers" << endl;
    Principia("{ 2n - 1 } from n=1 to infinity");
}

void b1()
{
    Principia("{ ((-1)^(n+1)) * (1/n) } from n=1 to infinity");

    for (int n = 1; n <= 20; n++)
    {
        cout << "n = " << n << ": " << pow(-1, n+1) * (1/double(n)) << endl;
    }
}

void c1()
{
    Principia("{ 1/n! } from n=1 to infinity");

    for (int n = 1; n <= 20; n++)
    {
        cout << "n = " << n << ": " << double(1) / Factorial(n) << endl;
    }
}

void d1()
{
    Principia("{ ((-1)^(n+1)) / (1/n!) } from n=1 to infinity");

    for (int n = 1; n <= 20; n++)
    {
        cout << "n = " << n << ": " << double(1) / Factorial(n) << endl;
    }
}

void e1()
{
    Principia("{ sinus ((n * pi) / 2) } from n=1 to infinity");

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
    Principia("{(i*i - 4)} from i=1 to 20");

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
    Principia("{sin(i/10)} from i=0 to 32");

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
    Principia("{sqrt(4*i)} from i=0 to 16");

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
    Principia("sin(pi/4), n=7");
}

void b3()
{
    // Lag en funksjon for cos(x) med input parametre n og x, som returnerer Sn og |En|.
    Principia("cos(pi/4), n=7");
}

void c3()
{
    // Lag en funksjon for e^x med input parametre n og x, som returnerer Sn og |En|.
    Principia("e^(1.0), n=1");
}

void d3()
{
    // Lag en funksjon som beregner sin(x) + cos(x) med input parametre n og x,
    // som returnerer Sn og |En|.
    Principia("sin(pi/4) + cos(pi/4), n=7");
}

void e3()
{
    // Ekstraoppgave: Potensrekka for en funksjon er mest nøyaktig rundt sentrum
    // for rekka, som her er x=0. For sinus og cosinus er det egentlig nok å beregne
    // verdien i første kvadrant, og deretter bruke det vi vet om at sinus og cosinus
    // er periodiske, samt hvilke kvadrant de er positive og negative i. Bruk denne
    // kunnskapen til å forbedre din beregning av sinx og cosx i a og b slik at de
    // blir ganske nøyaktige for alle verdier av x uten at du har alt for stor n. NB!
    // Isteden for å bruke potensrekka til å beregne sinx og cosx i første kvadrant,
    // kan en beregne for
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

    a3();
    b3();
    c3();
    d3();
    e3();
}

void four()
{

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

    one();
    two();
    three();
    four();

    while(true)
    Principia();

    return 0;
}
