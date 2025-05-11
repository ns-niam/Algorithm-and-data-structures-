#include <bits/stdc++.h>

using namespace std;

int main (){
    int a, b, count = 0;
    cin >> a >> b;
    int arr [a][b];
    for ( int i = 0; i < a; i++ ){
        for ( int j = 0; j < b; j++ ){
            cin >> arr [i][j];
            if (0 > arr[i][j]) count++;
        }
    }
    cout << count;
}