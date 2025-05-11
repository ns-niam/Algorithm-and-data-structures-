#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    map<char, int> m;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        m[c] = count(s.begin(), s.end(), c);
    }
    for (const auto& [key, value] : m)
        cout << key << " - " << value << endl;

}