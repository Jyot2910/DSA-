#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout<<"Enter a string: " ;
    cin.get(str, 100);

    char words[20][20];
    int len[20];
    int i = 0, j = 0, w = 0;

  
    while (1) {
        if (str[i] != ' ' && str[i] != '\0') {
            words[w][j++] = str[i];
        } else {
            words[w][j] = '\0';
            len[w] = j;
            w++;
            j = 0;

            if (str[i] == '\0')
                break;
        }
        i++;
    }

    
    for (i = 0; i < w - 1; i++) {
        for (j = 0; j < w - i - 1; j++) {
            if (len[j] > len[j + 1]) {
                
                int t = len[j];
                len[j] = len[j + 1];
                len[j + 1] = t;

              
                char temp[20];
                int k = 0;

                while (words[j][k] != '\0') {
                    temp[k] = words[j][k];
                    k++;
                }
                temp[k] = '\0';

                k = 0;
                while (words[j + 1][k] != '\0') {
                    words[j][k] = words[j + 1][k];
                    k++;
                }
                words[j][k] = '\0';

                k = 0;
                while (temp[k] != '\0') {
                    words[j + 1][k] = temp[k];
                    k++;
                }
                words[j + 1][k] = '\0';
            }
        }
    }

  
    cout << "Sorted words:";
    for (i = 0; i < w; i++)
        cout << words[i] << " ";

    return 0;
}