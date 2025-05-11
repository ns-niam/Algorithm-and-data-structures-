#include <bits/stdc++.h>

using namespace std;

void joke (int a, int s){
    int w = 0;
    int b = a;
    for ( int i = 0; i < s; i++ ){
        w += a % 10;
        a /= 10;
    }
    if ( w % ( b % 10 ) == 0 ) {
        cout << "Yes";
    } else{
        cout << "No";
    }
}

int main (){
    int a, s = 0, b;
    cin >> a;
    b = a;
    while (a != 0){
        a /= 10;
        s++;
    }
    joke( b, s );
    return 0;
}