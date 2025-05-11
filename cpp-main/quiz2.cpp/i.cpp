#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n][n], max1[n] = {INT_MIN};

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            max1[i] = max(max1[i], arr[i][j]); // max1[i] is the maximum value of the first row of the i-th column
        }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << max1[i] << " ";
        cout << endl;
    }
    return 0;
}