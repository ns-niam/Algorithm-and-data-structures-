#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    char d;
    int a;
    cin >> s >> d >> a;
    if (count(s.begin(), s.end(), d) == a) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}