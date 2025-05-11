#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, a, c = 0;
    cin >> n >> a;
    int arr[n][a];
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < a; j++ ){
            cin >> arr[i][j];
        }
    }
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < a; j++ ){
            c += arr[i][j];
        }
        cout << "The sum of row number " << i + 1 << " is " << c << endl;
        c = 0;
    }
    for ( int i = 0; i < a; i++ ){
        for ( int j = 0; j < n; j++ ){
            c += arr[j][i];
        }
        cout<< "The sum of column number " << i + 1 << " is " << c << endl;
        c = 0;
    }
    return 0;
}