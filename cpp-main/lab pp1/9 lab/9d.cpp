#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    int arr [n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr [i] == m) cnt++;
    }
    cout << cnt << endl;
    return 0;
}