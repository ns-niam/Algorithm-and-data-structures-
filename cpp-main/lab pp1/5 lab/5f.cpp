#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    int n , x;
    cin >> n >> x;
    for (int i = n; i < x + 1; i++){
        cout << s[i];
    }
    return 0;
}