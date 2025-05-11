#include <bits/stdc++.h>

using namespace std;

int main (){
    string s, a;
    cin >> s;
    a = s;
    reverse(s.begin(), s.end());
    if (s == a) cout << "YES";
    else cout << "NO";
    return 0;
}