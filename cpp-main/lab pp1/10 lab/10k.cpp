#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;\
    cin >> n;
    int arr [n], cnt = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        int n = 0;
        if(arr[i] != 0 || abs(arr[i]) != 1) {
        for(int j = 1; j <= abs(arr[i]); j++){
            if(abs(arr[i]) % j == 0) n++;
        }
        }
        if (n == 2) cnt++;
        n = 0;
    }
    cout << cnt << endl;
    return 0;
}