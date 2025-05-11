#include <bits/stdc++.h>

using namespace std;

string binary (int l){
    string s;
    for (int i = 0; i < 32; i++){
        s += to_string(l & 1);
        l = l >> 1;
    }
    for (int i = 32; i > 0; i--){
        if (s[i - 1] != '1') s.erase(i - 1, 1);
        else if (s[i - 1] == '1') break;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    int n;
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n; i++){
        cout << binary(v[i]) << endl;
    }
}