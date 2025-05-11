#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    int m = 0, k = 0;
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            if (i == 0){
                cout << j << " ";
            }
            else if (i != 0 && j == 0){
                cout << i << " ";
            }
            else if (i != 0 && j != 0){
                cout << i * j << " ";
            }
        }
        cout << endl;
    }
}