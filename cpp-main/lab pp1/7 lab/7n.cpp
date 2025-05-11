#include <bits/stdc++.h>

using namespace std;

string joke (int a, int b){
    int arr[a];
    for (int i = 0; i < a; i++){
        cin >> arr[i];
    }
    sort(arr, arr + a);
    for (int i = 0; i < a; i++){
        if (arr[i] - arr[i - 1] < b && i != 0) return "cheater";
    }
    return "no";
}

int main (){
    int a, b;
    cin >> a >> b;
    cout << joke(a, b) << endl;
    return 0;
}