#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, max2 = INT_MIN;
    cin >> n;
    int arr [n][n];
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            cin >> arr[i][j];
            max2 = max(max2, arr[i][j]);
        }
    }
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            if ( arr [i][j] == max2 ){
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
}