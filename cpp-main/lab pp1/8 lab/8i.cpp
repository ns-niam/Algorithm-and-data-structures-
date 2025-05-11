#include <bits/stdc++.h>

using namespace std;

int main (){
    int t;
    cin >> t;
    int arr [t];
    for (int i = 0; i < t; i++){
        cin >> arr[i];
    }
    int d;
    cin >> d;
    for (int i = 0; i < t; i++){
        if (arr[i] == d){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No";
    return 0;
}