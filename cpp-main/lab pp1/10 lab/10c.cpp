#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    stack <char> st;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if(st.empty()) st.push(s[i]);
        else if (!st.empty()){
            int n;
            n = (st.top() - '0') * 10 + (s[i] - '0');
            if ((int) sqrt(n) * (int) sqrt(n) == (int) n) st.pop();
            else st.push(s[i]);
        }
    }
    if (st.empty()) cout << "Stack is empty";
    else while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}