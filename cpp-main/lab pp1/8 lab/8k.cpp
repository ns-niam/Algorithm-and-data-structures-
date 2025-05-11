#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector <int> c(n);
    for (int i = 0; i < n; i++){
        cin >> c [i];
    }
    int b;
    cin >> b;
    int sum = 0;
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    for (int i=0; i<b; i++){
        sum += c[i];
        }
    cout << sum;
}