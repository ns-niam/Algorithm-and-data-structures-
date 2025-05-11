#include <bits/stdc++.h>

using namespace std;

string palindrom (string s){
    string a = s;
    reverse (s.begin(),s.end());
    if (a==s) return "Yes";
    else return "No";
}

int main (){
    string s;
    cin >> s;
    cout << palindrom(s) << endl;
    return 0;
}