#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, m, min_sum = INT_MAX, pos = 0, sum = 0;
    cin >> n >> m;
    int arr [n][m];
    for ( int i = 0; i < n; i++){
        for ( int j = 0; j < m; j++ ){
            cin >> arr[i][j];
            sum += arr[i][j];
        }
        if ( sum < min_sum ){
            min_sum = sum;
            pos = i + 1;
        }
        sum = 0; 
    }
    cout << pos << endl;
    return 0;
}