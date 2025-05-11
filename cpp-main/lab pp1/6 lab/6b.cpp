#include <bits/stdc++.h>

using namespace std;

void joke (int a, vector <int> &arr){
    for ( int i = 0; i < a; i++ ){
        arr[i] = abs(arr[i] - arr[i + a]);
    }
}
int main(){
    int n;
    cin >> n;
    vector <int> arr(n * 2);
    for ( int i = 0; i < n * 2; i++ ){
        cin >> arr[i];
    }
    joke(n, arr);
    for ( int i = 0; i < n; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}