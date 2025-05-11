#include <bits/stdc++.h>

using namespace std;

bool check (bool falg, vector <map<char, int>> v){
    for (char flag = 'a'; flag <= 'z'; flag++){
        bool flag_check = true;
        for (auto c : v){
            if (c[flag] == 0) flag_check = false;
        }
        if (flag_check) {
            cout << flag << " ";
            falg = true;
            }
    }
    return falg;
}

int main (){
    int n;
    cin >> n;
    vector <map<char, int>> v;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        map<char, int> m;
        for (int j = 0; j < s.size(); j++){
            m[s[j]]++;
        }
        v.push_back(m);
    }
    bool flag = false;
    flag = check (flag, v);
    if (!flag) cout << "NO COMMON CHARACTERS";
    return 0;
}