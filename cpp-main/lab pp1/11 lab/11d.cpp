#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, s;
    bool check = true;
    cin >> n >> s;
    int arr[n][s];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < s; j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j + 1] == arr[i][j] && arr[i + 1][j + 1] == arr[i][j] && arr[i + 1][j]==arr[i][j]){
                check = false;
                break;
            }
        }
        if (!check) break;
    }
    if (check) cout << "YES";
    else cout << "NO";
    return 0;
}