#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; //works with large digits
    cin >> s;

    int n = s[0] - '0'; //find first digit
    int sum_digits = 0;

    for(int i = 1; i < s.size(); i++)
        sum_digits += (s[i] - '0'); //sum digits

    if (sum_digits % 10 == n) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}