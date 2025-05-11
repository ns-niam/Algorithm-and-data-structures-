#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto i : s){
        if ((int) i + n <= 90) cout << (char) (i + n);
        else cout << (char) (i + n - 26);
    }
}