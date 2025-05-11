#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    string s [n];
    int d [n];
    int sum = 0;
    map <string, int> m;
    for (int i = 0; i < n; i++){
        cin >> s[i] >> d[i];
        m[s[i]] += d[i];
    }
    for (map <string, int>::iterator it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }   
    return 0;
}