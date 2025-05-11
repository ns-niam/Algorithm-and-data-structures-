#include <bits/stdc++.h>

using namespace std;

void joke (vector<int> v, int n){
    int cnt = 0;
    for (int i = 0; i < v.size(); i++){
        cnt = count(v.begin(), v.end(), v[i]);
    }
    if (cnt != n){
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    while(next_permutation(v.begin(), v.end())){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    }
    else cout << v[0];
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int c;
        cin >> c;
        if (find(v.begin(), v.end(), c) == v.end()){
            v.push_back(c);
        }
    }
    joke(v, n);
    return 0;
}