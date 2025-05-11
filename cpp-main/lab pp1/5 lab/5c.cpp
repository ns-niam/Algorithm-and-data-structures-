#include <bits/stdc++.h>

using namespace std;

int main (){
    string s, a;
    cin >> s >> a;
    size_t as = s.find(a);
    if (as != string::npos) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}