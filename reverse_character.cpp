#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout<<"Enter a string : ";
    cin.get(str, 100);

    int start = 0;
    int i = 0;

    while (true) {
        if (str[i] == ' ' || str[i] == '\0') {
            int end = i - 1;

            
            while (start < end) {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }

            if (str[i] == '\0')
                break;

            start = i + 1;
        }
        i++;
    }

    cout << str;

    return 0;
}