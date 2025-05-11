#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v (n);
    int arr[i] = {0};
    for(int i = 0; i < n; i++){
        int k ,l;
        cin >> k >> l;
        arr[i] = count(v.begin(), v.end(), {k,l});
        if(k > l) v[i] = {l,k};
        else v[i] = {k,l};
    }
    for(int i = 0; i < n; i++) cout << arr[i] << endl;
    return 0;
}