#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    char c;
    cin >> s >> c;
    int g = 0, d = 0;
    for(int i = 0; i < s.length(); i++)
        if(s[i] == c){
            g = i;
            break;
        }
    for(int i = s.length() - 1; i >= 0; i--)
        if(s[i] == c){
            d = i;
            break;
        }
    if(d == g) cout << d << endl;
    else cout << g << " " << d << endl;
    return 0;
}