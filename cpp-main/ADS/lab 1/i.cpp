#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    char c;
    queue<int> q, q1;
    for (int i = 0; i < n; i++){
        cin >> c;
        if (c == 'K') q.push(i);
        else q1.push(i);
    }
    while (!q.empty() && !q1.empty()){
        int kat = q.front(), sak = q1.front();
        q.pop();
        q1.pop();
        if (kat < sak) q.push(kat + n);
        else q1.push(sak + n);
    }
    cout << (q.empty() ? "SAKAYANAGI" : "KATSURAGI");
    return 0;
}