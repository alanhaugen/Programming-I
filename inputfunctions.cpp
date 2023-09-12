#include "inputfunctions.h"

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
