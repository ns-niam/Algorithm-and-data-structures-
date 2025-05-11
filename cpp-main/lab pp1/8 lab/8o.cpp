#include <bits/stdc++.h>

using namespace std;

int count (string q, int cnt){
    for (int i = 0; i < q.length(); i++){
        if (q[i] != q[i - 1]) cnt++;
    }
    return cnt;
}

string joke (string s){
    for (int i = 0; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }
    return s;
}
string sort (string a){
    sort(a.begin(), a.end());
    return a;
}

int main (){
    string d;
    cin >> d;
    int cnt = 0;
    d = joke(d);
    d = sort(d);
    cout << count(d, cnt) << endl;
    for (int i = 0; i < d.length(); i++){
        if (d[i] != d[i - 1]) cout << d [i] << " ";
    }
    return 0;
}