#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, c, d;
    cin >> m >> c >> d;
    long long n [m], s = 0;
    for ( int i = 0; i < m ; i++ ){
        cin >> n [i];
    }
    for ( int i = c; i <= d; i++ ){
        s += n [i - 1];
    }
    cout << s;
    return 0;
}