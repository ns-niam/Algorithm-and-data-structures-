#include <bits/stdc++.h>

using namespace std;
int joke(){
    int n, sum = 0;
    cin >> n;
    while (n != 0){
        sum += (n % 10) / 2;
        n /= 10;
    }
    return sum;
}
int main (){
    cout << joke ();
    return 0;
}