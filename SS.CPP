#include <iostream>
using namespace std;

int main() {
    char str[100], word[20][20], temp[20];
    int len[20];
    int i = 0, j = 0, k = 0, l;
    cout << "Enter a string: ";
    cin.get(str, 100);

    
    while (1) {
        if (str[i] != ' ' && str[i] != '\0') {
            word[k][j++] = str[i];
        } else {
            word[k][j] = '\0';
            len[k] = j;
            k++;
            j = 0;
            if (str[i] == '\0')
                break;
        }
        i++;
    }

   
    for (i = 0; i < k - 1; i++) {
        for (j = 0; j < k - i - 1; j++) {

            bool swapNeeded = false;

           
            if (len[j] > len[j + 1])
                swapNeeded = true;

            
            else if (len[j] == len[j + 1]) {
                int p = 0;
                while (word[j][p] == word[j + 1][p] &&
                       word[j][p] != '\0')
                    p++;

                if (word[j][p] > word[j + 1][p])
                    swapNeeded = true;
            }

            if (swapNeeded) {
                
                int t = len[j];
                len[j] = len[j + 1];
                len[j + 1] = t;

               
                for (l = 0;; l++) {
                    temp[l] = word[j][l];
                    if (temp[l] == '\0') break;
                }

                for (l = 0;; l++) {
                    word[j][l] = word[j + 1][l];
                    if (word[j + 1][l] == '\0') break;
                }

                for (l = 0;; l++) {
                    word[j + 1][l] = temp[l];
                    if (temp[l] == '\0') break;
                }
            }
        }
    }

    for (i = 0; i < k; i++)
        cout << word[i] << " ";

    return 0;
}