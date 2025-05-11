#include <bits/stdc++.h>

using namespace std;

int main (){
    int a;
    cin >> a;
     int b = 0 , b1 = a - 1 , c = 0 , c1 = a - 1;
     int arr [a][a];
     int k = 1 ;
     while (k <= ( a * a )){
        for ( int i = b; i <= b1; i++){
            arr [c][i] = k++ ;
        }
        for ( int i = c + 1; i <= c1; i++){
            arr [i][b1] = k++ ; 
        }
        for ( int i = b1 - 1; i >= b; i--){
            arr [c1][i] = k++ ;
        }
        for ( int i = c1 - 1; i >= c + 1; i--){
            arr [i][b] = k++ ;
        }
        b++;
        b1--;
        c++;
        c1--;
     } 
     for ( int i = 0; i < a; i++){
        for ( int j = 0; j < a; j++){
            cout << arr [i][j] << " ";
        }
        cout << endl;
     }
}