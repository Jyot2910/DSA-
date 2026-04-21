#include <iostream>
using namespace std;

int minNum(int a, int b){
    if(a < b) return a;
    else return b;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << minNum(a, b);
}

