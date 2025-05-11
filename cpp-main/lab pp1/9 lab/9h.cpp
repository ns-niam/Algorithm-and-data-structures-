#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    map <string, int> mp;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        mp.insert(pair<string, int>(s, i + 1));
    }
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}