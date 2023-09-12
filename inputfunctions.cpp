#include "inputfunctions.h"

int GetInteger()
{
    int input;
    bool fail = true;

    do
    {
        cin >> input;

        // Error handling for cin
        if (cin.fail())
        {
            cout << "Please enter numbers only\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            fail = false;
        }
    }
    while (fail);

    return input;
}

double GetDouble()
{
    double input;
    bool fail = true;

    do
    {
        cin >> input;

        // Error handling for cin
        if (cin.fail())
        {
            cout << "Please enter numbers only\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            fail = false;
        }
    }
    while (fail);

    return input;
}

string GetString()
{
    string input;
    bool fail = true;

    do
    {
        cin >> input;

        // Error handling for cin
        if (cin.fail())
        {
            cout << "Please enter numbers only\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            fail = false;
        }
    }
    while (fail);

    return input;
}
