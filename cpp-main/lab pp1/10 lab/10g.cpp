#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    map <pair<pair<string, int>, pair<string, int>>, int> m;
    for (int i = 0; i < n; i++){
        string s1, s2;
        int x, y;
        cin >> s1 >> x >> s2 >> y;
        m[make_pair(make_pair(s1, x), make_pair(s2, y))] = x + y;
    }
    for(auto it = m.begin(); it != m.end(); it++){
        cout << it->first.first.first << " and " << it->first.second.first << " " << it->second << endl;
    }
    return 0;
}