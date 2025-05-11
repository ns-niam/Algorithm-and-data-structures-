#include <bits/stdc++.h>

using namespace std;

string joke (string s, string t){
    int n = s.length();
    t.erase(0, (t.length() - s.length()));
    return t;
}

int main (){
    string s, t;
    cin >> s >> t;
    t = joke (s, t);
    cout << (t.find(s) == 0 ? "YES" : "NO"); 
    return 0;
}