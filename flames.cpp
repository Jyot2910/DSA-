#include <iostream>
#include <string>
using namespace std;

int main() {
    string name1, name2;

    cout << "Enter First Name: ";
    getline(cin, name1);

    cout << "Enter Second Name: ";
    getline(cin, name2);

    
    string a = "", b = "";

    for (char ch : name1) {
        if (ch != ' ') {
            if (ch >= 'A' && ch <= 'Z')
                ch = ch + 32;
            a += ch;
        }
    }

    for (char ch : name2) {
        if (ch != ' ') {
            if (ch >= 'A' && ch <= 'Z')
                ch = ch + 32;
            b += ch;
        }
    }

      
    bool used[100] = {false};
    int count = 0;

    for (int i = 0; i < a.length(); i++) {
        bool found = false;
        for (int j = 0; j < b.length(); j++) {
            if (!used[j] && a[i] == b[j]) {
                used[j] = true;
                found = true;
                break;
            }
        }
        if (!found)
            count++;
    }

    for (int j = 0; j < b.length(); j++) {
        if (!used[j])
            count++;
    }

    string flames = "FLAMES";

    while (flames.length() > 1) {
        int index = (count - 1) % flames.length();
        flames.erase(index, 1);

        if (index != flames.length()) {
            flames = flames.substr(index) + flames.substr(0, index);
        }
    }

    cout << "\nRelationship: ";

    switch (flames[0]) {
        case 'F':
            cout << "Friends";
            break;
        case 'L':
            cout << "Love";
            break;
        case 'A':
            cout << "Affection";
            break;
        case 'M':
            cout << "Marriage";
            break;
        case 'E':
            cout << "Enemies";
            break;
        case 'S':
            cout << "Siblings";
            break;
    }

    return 0;
}