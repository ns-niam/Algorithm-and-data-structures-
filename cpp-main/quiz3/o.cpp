#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int max1 = 0;
    char f;
    for(int i = 0; i < s.length(); i++){
        if(f == s[i]) continue;
        if(max1 < count(s.begin() + i, s.end(), c)){
            max1 = count(s.begin() + i, s.end(), c);
            f = c;
        }
    }
    cout << f << " " << max1 << endl;
    return 0;
}