#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

int main()
{
    srand (time(NULL)); // Do this only once (initialise random)

    int guess = rand() % 100; // Make a random number from 0 to 100
    int attempts = 10;
    int input;

    cout << "Guess which number I am thinking of (0 - 100): ";

    while (attempts > 0)
    {
        cin >> input;

        // Error handling for cin
        if (cin.fail())
        {
            cout << "Please enter numbers only" << endl;
            std::cin.clear();
            std::cin.ignore();

            continue;
        }

        attempts--;

        if (input < guess)
        {
            cout << "Wrong. Too low! You have " << attempts << " attempts left. Try again: ";
        }
        else if (input > guess)
        {
            cout << "Wrong. Too high! You have " << attempts << " attempts left. Try again: ";
        }
        else
        {
            cout << endl << "You are right. You win! " << endl;
            return 0;
        }
    }

    cout << endl << "Game over...";

    return 0;
}
