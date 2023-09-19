#include "inputfunctions.h"

/// Returns an integer, will ask user for an integer until a whole number is typed
int GetInteger(string message)
{
    int input;
    bool fail = true;

    cout << message;

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

/// Returns an integer, will ask user for an integer until a whole positive number is typed
unsigned int GetUnsignedInteger(string message)
{
    unsigned int input;
    bool fail = true;

    cout << message;

    do
    {
        cin >> input;

        // Error handling for cin
        if (cin.fail())
        {
            cout << "Please enter positive numbers only\n";
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

/// Returns an double (high precision float),
/// will ask user for an decimal number until a decimal number is typed
/// NOTE: Decimal numbers are like this: 1.1 2.3 1.5 etc. (with a . )
/// Not: 1,1 2,3 1,5 etc. (C++ uses the American system)
double GetDouble(string message)
{
    double input;
    bool fail = true;

    cout << message;

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

/// Returns a string (letters),
/// will ask user for letter characters until they have been typed
string GetString(string message)
{
    string input;
    bool fail = true;

    cout << message;

    do
    {
        cin >> input;

        // Error handling for cin
        if (cin.fail())
        {
            cout << "Please enter letters only\n";
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
