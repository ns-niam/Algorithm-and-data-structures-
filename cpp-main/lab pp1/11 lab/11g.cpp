#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    map <string, set <int>> m;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;         
        cin >> s;
        int d;
        cin >> d;
        m[s].insert(d);
    }
    for (auto it : m){
        cout << it.first << " ";
        if (it.second.size() < 3) cout << "NO BONUS" << endl;
        else cout << "+1" << endl;
    }
    return 0;
}