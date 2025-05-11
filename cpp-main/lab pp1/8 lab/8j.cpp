#include <bits/stdc++.h>

using namespace std;

int main (){
    int a, max1 = INT_MIN, min1 = INT_MAX;
    cin >> a;
    int arr [a];
    for (int i = 0; i < a; i++){
        cin >> arr[i];
        max1 = max(arr[i], max1);
        min1 = min(arr[i], min1);
    }
    cout << abs(max1 - min1) << endl;
    return 0;
}