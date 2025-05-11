#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int max1 = INT_MIN, max2 = INT_MIN; //#include <climits>
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        max1 = max(max1, arr[i]); //find first maximum
    }

    for (int i = 0; i < n; i++){
        if(max1 == arr[i]) arr[i] = 0; //if first maximum is equal to current element, set it to 0 (for fun)
        else max2 = max(max2, arr[i]); //find second maximum
    }

    cout << max2 * max1 << endl;
    return 0;
}