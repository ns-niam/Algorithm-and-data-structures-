#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, a = 1; 
    cin >> n;
    while (a <= n){
        a++;
        if ( a == 2 || a == 3 || a == 5 || a == 7){
            cout << a << " is prime"<< endl;
        }
    }
    a = 1;
    while (++a <= n) {
        if ( a % 2 != 0 && a % 3 != 0 && a % 5 != 0 && a % 7 != 0){
            cout << a << " is prime" << endl;
        }
    }
}