#include <iostream>
#include <string>
using namespace std;

bool isAlphaNum(char c) {
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
        return true;
    return false;
}

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
        if (!isAlphaNum(s[i])) i++;
        else if (!isAlphaNum(s[j])) j--;
        else {
            if (tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
    }
    return true;
}

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    if (isPalindrome(s))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}