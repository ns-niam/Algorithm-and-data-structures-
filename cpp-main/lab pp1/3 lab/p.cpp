#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a=sqrt(n);
    if (a*a==n){
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}