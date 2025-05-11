#include <bits/stdc++.h>

using namespace std;

void joke (vector<int> &v, int n, int a){
    for ( int i = 0; i < n; i++){
        if (v[i] == a){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}
int main(){
    int n, a;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> a;
    joke(v, n, a);
    return 0;
}