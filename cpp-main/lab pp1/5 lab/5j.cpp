#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1, s2;
    cin >> s1;
    s1 += s1[0];
    s2 = s1;
    reverse(s1.begin(), s1.end());
    if(s2 == s1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}