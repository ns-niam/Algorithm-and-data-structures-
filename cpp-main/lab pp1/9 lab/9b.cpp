#include <bits/stdc++.h>

using namespace std;

int odd (vector <int> v){
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++){
        if (v[i] % 2 != 0){
            cout << v[i] << " ";
            }
        }
    return 0;
}

int even (vector <int> v){
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++){
        if (v[i] % 2 == 0){
            cout << v[i] << " ";
        }
    }
    return 0;
}


int main (){
    int n;
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    even (v);
    odd (v);
    return 0;
}