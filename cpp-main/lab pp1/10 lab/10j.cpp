#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, a;
    cin >> n >> a;
    int arr [n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    reverse(arr, arr + a);
    reverse(arr + a, arr + n);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}