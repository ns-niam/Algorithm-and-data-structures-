#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    stack<int> st;
    vector<int> v;
    queue<int> ans;

    for (int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < v.size(); i++){
        while (!st.empty() && st.top() > v[i]){
            st.pop();
        }
        if (st.empty()) ans.push(-1);
        else ans.push(st.top());
        st.push(v[i]);
    }
    while (!ans.empty()){
        cout << ans.front() << ' ';
        ans.pop();
    }
    return 0;
}
