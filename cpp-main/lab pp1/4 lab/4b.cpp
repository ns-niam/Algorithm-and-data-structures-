#include <iostream>
#include <climits>

using namespace std;

int main(){
    int n, max = INT_MIN, max2 = INT_MIN, again = 0;
    cin >> n;
    int a [n][n];
        for ( int j = 0; j < n; j++ ) {
            for ( int k = 0; k < n; k++ ){
                cin >> a[k][j];
                max = a[k][j] > max ? a[k][j] : max;
            }
        }
        for ( int j = 0; j < n; j++ ) {
            for ( int k = 0; k < n; k++ ){
                max2 = a[j][k] < max && max2 < a[j][k] ? a[j][k] : max2;
                if ( a[j][k] == a[j][k - 1] ) {
                    again++;
                }
            }
        }
        cout << (again + 1 == n * n ? 0 : max2);
    return 0;
}
