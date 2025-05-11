#include <bits/stdc++.h>

using namespace std;

int main (){
    queue <string> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int d;
        cin >> d;
        if (d == 2) q.pop();
        else {
            string s;
            cin >> s;
            q.push(s);
        }
        if (!q.empty()) cout << q.front() << endl;
        else cout << "queue is empty" << endl;
    }
    return 0;

}