#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    map <int, int> m;
    cin >> n;
    int arr [n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        m[arr[i]] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if (m[arr[i] ^ arr[j]]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}