#include <bits/stdc++.h>

using namespace std;

vector<int> prefixFunction(const string& s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
            j = pi[j - 1];
        if (s[j] == s[i])
            ++j;
        pi[i] = j;
    }
    return pi;
}

int main(){
    int n;
    cin >> n;
    while (n--) {
        string s;
        int k;
        cin >> s >> k;
        
        vector<int> pi = prefixFunction(s);
        int overlap = pi[s.size() - 1]; 
        
        int shortestLength = s.size() + (k - 1) * (s.size() - overlap);
        
        cout << shortestLength << endl;
    }
}