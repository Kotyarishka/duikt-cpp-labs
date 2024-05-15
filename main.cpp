#include <iostream>
using namespace std;

int main()
{
    cout << "Enter password: ";
    string password;
    getline(cin, password);

    // password must be
    // 1. be 8 characters long
    // 2. have at least one uppercase letter
    // 3. have at least one lowercase letter
    // 4. have at least one digit
    // 5. have at least one special character

    bool validPassword = true;
    if (password.length() != 8)
    {
        validPassword = false;
        cout << "Password must be 8 characters long" << endl;
    }

    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;
    bool hasSpecialCharacter = false;

    for (int i = 0; i < password.length(); i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            hasUpperCase = true;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            hasLowerCase = true;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            hasDigit = true;
        }
        else
        {
            hasSpecialCharacter = true;
        }
    }

    if (!hasUpperCase)
    {
        validPassword = false;
        cout << "Password must have at least one uppercase letter" << endl;
    }
    if (!hasLowerCase)
    {
        validPassword = false;
        cout << "Password must have at least one lowercase letter" << endl;
    }
    if (!hasDigit)
    {
        validPassword = false;
        cout << "Password must have at least one digit" << endl;
    }
    if (!hasSpecialCharacter)
    {
        validPassword = false;
        cout << "Password must have at least one special character" << endl;
    }

    if (validPassword)
    {
        cout << "Password is valid" << endl;

        return 0;
    } else
    {
        cout << "Password is invalid" << endl;
        cout << "Please try again" << endl;

        return 1;
    }
}