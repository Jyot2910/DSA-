#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout<<"Enter a string : ";
    cin.get(str, 100);   

    int len = 0;

    
    while (str[len] != '\0')
        len++;

    int i = len - 1;

    while (i >= 0) {

       
        while (i >= 0 && str[i] == ' ')
            i--;

        if (i < 0)
            break;

        int end = i;

        
        while (i >= 0 && str[i] != ' ')
            i--;

       
        for (int j = i + 1; j <= end; j++)
            cout << str[j];

        if (i > 0)
            cout << " ";
    }

    return 0;
} 