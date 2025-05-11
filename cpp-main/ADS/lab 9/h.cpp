#include <bits/stdc++.h>
using namespace std;
vector<int> prefixFunction(string s){
    vector<int> pi(s.size());
    pi[0] = 0;
    for (int i = 1; i < s.size(); i++){
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
            j = pi[j - 1];
        if (s[j] == s[i])
            pi[i] = j + 1;
        else
            pi[i] = 0;
    }

    return pi;
}
int main(){
    string s;
    cin >> s;
    vector<int> res = prefixFunction(s);
    int ans = 0, n = s.size();
    for (int i = 1; i < n; i++){
        int len = i - res[i - 1];
        if ((i / len) % 2 == 0 && i % len == 0)r
            ans++;
    }
    cout << ans;
}