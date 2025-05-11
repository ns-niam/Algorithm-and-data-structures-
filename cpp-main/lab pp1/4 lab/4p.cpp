#include <bits/stdc++.h>

using namespace std;

int main (){
    int a, sum = 0, s = 0;
    cin >> a;
    int arr [a][a];
    for ( int i = 0; i < a; i++ ){
        for ( int j = 0; j < a; j++ ){
            cin >> arr[i][j];
        }
    }
    s = a - 1;
    for ( int i = 0; i < a ; i++ ){
        sum += arr [i][s--];
    }
    cout << sum;
}