#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    int idx = 0;

    for (int i = 0; i < n; i++) {
        char ch = chars[i];
        int count = 0;

        // count same characters
        while (i < n && chars[i] == ch) {
            count++;
            i++;
        }

        // write character
        chars[idx++] = ch;

        // write count if > 1
        if (count > 1) {
            string str = to_string(count);
            for (char c : str) {
                chars[idx++] = c;
            }
        }

        i--; // adjust for loop
    }

    return idx;
}

int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};

    int newLength = compress(chars);

    cout << "Compressed array: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }

    cout << "\nLength: " << newLength << endl;

    return 0;
}