#include <bits/stdc++.h>
using namespace std;

void bs(int left, int right, int target, int arr[]){
    int ans;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else{
            right = mid - 1;
            ans = mid;
        }
    }
    cout << ans+1 << endl;
}

int main(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int arr_copy[n];
    arr_copy[0] = arr[0];
    for (int i = 1; i < n; i++)
        arr_copy[i] = arr_copy[i - 1] + arr[i];
    while (m--){
        int x;
        cin >> x;
        bs(0, n - 1, x, arr_copy);
    }
    return 0;
}