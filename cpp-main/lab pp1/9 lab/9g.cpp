#include <bits/stdc++.h>

using namespace std;

int main (){
    stack <char> as;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i){
        if(!as.size()) as.push(s[i]);
        else if (as.top() == '1' && s[i] == '1') as.pop();
        else as.push(s[i]);
    }
    string answ = "";
    while (!as.empty()){
        answ += as.top();
        as.pop();
    }
    reverse(answ.begin(), answ.end());
    for (auto c : answ){
        cout << c;
    }
    return 0;
}