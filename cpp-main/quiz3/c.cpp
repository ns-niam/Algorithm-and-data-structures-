#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int max1 = INT_MIN;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            max1 = max(max1, __gcd(arr[i], arr[j]));
    cout << max1;
}