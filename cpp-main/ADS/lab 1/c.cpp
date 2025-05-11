#include <bits/stdc++.h>

using namespace std;

string get_coorect(string str) {
    deque<char>dq;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '#') dq.pop_back();
        else dq.push_back(str[i]);
    }
    string ans="";
    for(char c : dq) ans += c;
    return ans;
}

int main(){
    string frst, scnd; cin >> frst >> scnd;
    string check1 = get_coorect(frst), check2 = get_coorect(scnd);
    cout << (check1 == check2 ? "Yes" : "No") << endl;
}