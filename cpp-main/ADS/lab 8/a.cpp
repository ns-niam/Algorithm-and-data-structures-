#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long
int MOD = 1e9 + 7;
int multiplication = 11;

string hashing(string s){
    ull power = 1;
    ull ans = 0;
    for (int i = 0; i < s.size(); i++){
        ans = (ans + ((s[i] - 47) * power) % MOD) % MOD;
        power = (power * multiplication) % MOD;
    }
    return to_string(ans);
}

int main(){

    int n;
    cin >> n;
    unordered_map<string, string> st;
    vector<string> v(2 * n);
    for (int i = 0; i < v.size(); i++)
        cin >> v[i];
    for (int i = 0; i < 2 * n; i++){
        string hash = hashing(v[i]);
        if (find(v.begin(), v.end(), hash) != v.end())
            st[v[i]] = hash;
    }
    unordered_map<string, string>::iterator it;
    int cnt = 0;
    for (int i = 0; i < v.size(); i++){
        it = st.find(v[i]);
        if (it != st.end()){
            cout << "Hash of string " << '"' << it->first << '"' << " is " << it->second << endl;
            cnt++;
        }
        if (cnt == n)
            return 0;
    }
    return 0;
}