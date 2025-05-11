#include <bits/stdc++.h>

using namespace std;

int main(){
    string s = "@gmail.com";
    int d;
    cin >> d;
    vector<string> f;
    for(int i = 0; i < d; i++){
        string g;
        cin >> g;
        size_t found = g.find(s);
        if (found != string::npos){
            g.erase(g.end() - 10, g.end());
            f.push_back(g);
        }
    }
    for(int i = 0; i < f.size(); i++){
        cout << f[i] << endl;
    }
    return 0;
}