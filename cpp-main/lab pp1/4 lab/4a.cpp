#include <iostream>

using namespace std;

int main(){
    int n, max1 = INT_MIN;
    cout << max1 << " ";
    cin >> n;
    int a [n][n];
        for ( int i = 0; i < n; i++ ){
            for  ( int j = 0 ; j < n ; j++){
                cin >> a[i][j];
                max1 = max ( max1 , a[i][j]);
            }
        }
    cout << max1 << endl;

    return 0;
}