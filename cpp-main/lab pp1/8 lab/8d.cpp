#include <bits/stdc++.h>

using namespace std;

int main (){
    int a, v;
    cin >> a;
    int d [a];
    for ( int i = 0; i < a; i += 1){
        cin >> d[i];
    }
    cin >> v;
    for (int i = 0; i < a; i += 1){
        if (i != v){
            cout << d[i] << " ";
        }
    }
    return 0;
}