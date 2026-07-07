#include <iostream>
#include <string>
using namespace std;

int main() {
    string password;
    bool upper, lower, digit, special;
    int attempts = 0;

    while (attempts < 5) {
        upper = lower = digit = special = false;

        cout << "\nEnter Password: ";
        cin >> password;

      
        for (int i = 0; i < password.length(); i++) {
            if (password[i] >= 'A' && password[i] <= 'Z')
                upper = true;
            else if (password[i] >= 'a' && password[i] <= 'z')
                lower = true;
            else if (password[i] >= '0' && password[i] <= '9')
                digit = true;
            else
              special = true;
        }

       
        if (password.length() >= 8 && upper && lower && digit && special) {
            cout << "\nPassword is Strong (Valid)." << endl;
            cout << "Password Accepted!" << endl;
            return 0;
        }

       
        cout << "\nPassword is NOT Strong.\n";
        cout << "Reason(s):\n";

        if (password.length() < 8)
            cout << "Password must be at least 8 characters long.\n";

        if (!upper)
            cout << "Add at least one uppercase letter \n";

        if (!lower)
            cout << "Add at least one lowercase letter\n";

        if (!digit)
            cout << " Add at least one digit \n";

        if (!special)
            cout << " Add at least one special character \n";

        attempts++;

        if (attempts < 5)
            cout << "\nAttempts Left: " << 5 - attempts << endl;
    }

    cout << "\nOo Stree Ya Purursh Kal Aana " << endl;

    return 0;
}