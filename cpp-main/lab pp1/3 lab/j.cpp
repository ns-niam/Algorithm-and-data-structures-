#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, s;
    cin >> a >> s;
    int d [a];
    for ( int i = 0; i < a; i++ ){
        cin >> d [i];
    }
    for ( int i = 0; i < a; i++ ){
        if ( d [i] == s - 1 ){
            cout << i + 1 << endl;
            break;
        } else if ( d [i] == s){
            cout << i << endl;
            break;
        } else if ( d [i] > s ){
            cout << i << endl;
            break;
        }
    }
    
}