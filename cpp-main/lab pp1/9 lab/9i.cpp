#include <bits/stdc++.h>

using namespace std;

int main (){
    vector <string> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        v.push_back(s);
        if (count(v.begin(), v.end(), s) == 1) cout << "new user added" << endl;
        else cout << "user already exists" << endl;
    }
    return 0;
}