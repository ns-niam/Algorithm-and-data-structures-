#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int sum = 0;
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++) sum += (s[i] - '0') * pow(2, i);
    cout << sum << endl;
    return 0;
}