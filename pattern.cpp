#include <iostream>
using namespace std;

int main() {
    int n = 4 ;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << j ;
        }
       cout << endl;
    }


    char ch = 'A';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }


    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < i+1 ; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    ch = 'A';
     for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < i+1 ; j++) {
            cout << ch << " ";
            }
        cout << endl;
        ch++;
}


     for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < i+1 ; j++) {
            cout << j+1 << " ";
        }
        cout << endl;
}

        for (int i = 0 ; i < n; i++) {
            for (int j = i+1 ; j >0  ; j--) {
                cout << j << " ";
            }
            cout << endl;
}
  
int num = 1 ;
 for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < i+1 ; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
}

 for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++) {
            cout << (i + 1);
        }

        cout << endl;
    }


for (int i = 1; i <= n; i++) {
       
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

      
        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        
        for (int j = i - 1; j > 0 ; j--) {
            cout << j;
        }

        cout << endl;
    }


    
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) cout << " ";
    for (int j = 1; j <= 2*i - 1; j++) {
        if (j == 1 || j == 2*i - 1) cout << "*";
        else cout << " ";
    }
    cout << endl;
}

for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= n - i; j++) cout << " ";
    for (int j = 1; j <= 2*i - 1; j++) {
        if (j == 1 || j == 2*i - 1) cout << "*";
        else cout << " ";
    }
    cout << endl;
}
}









