#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr [n][n];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(arr[i][j] != arr[j][i]){ //finds the non-equal elements
                cout << "Not perfect.";
                return 0;
            }
    
    cout << "Perfect.";
    return 0;
}