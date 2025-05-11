#include <bits/stdc++.h>

using namespace std;

char couty ( int b ){
    if (b >= 10)
        return 'A' + b - 10;   
    return '0' + b;
}

void rec ( int c, int f ){
    if ( c == 0 ) return;
    rec( c / f, f );
    cout << couty ( c % f );
}

int main(){
    int c, f; 
    cin >> c >> f;
    rec( c, f );
}