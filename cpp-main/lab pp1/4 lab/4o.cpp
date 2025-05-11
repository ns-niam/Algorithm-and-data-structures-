#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d = -1000000;
    cin >> n;
    int a [n][n];
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ){
            cin >> a [i][j];
        }
    }
    for ( int i = 0; i < n; i++ ) {
        d = max( d, a [i][i] );
    }
    cout << "Maximum element is: " << d << " " ;
    for ( int i = 0; i < n; i++ ){
        if ( d == a [i][i]){
                cout << "with coordinates: " << i + 1 << ";" << i + 1;
                break;
        }
    }
}