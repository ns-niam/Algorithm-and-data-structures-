#include <bits/stdc++.h>

using namespace std;

void joke (int a, vector<int> &v){
    for (int i = a - 1; i >= 0; i--){
        cout << v[i] << " ";
    }
}
int main (){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    joke (n, v);
    return 0;    
}