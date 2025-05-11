#include <bits/stdc++.h>

using namespace std;

int main (){
    int a;
    cin >> a;
    int arr [a];
    for (int i = 0; i < a; i++){
        cin >> arr[i];
    }
    int b, c;
    cin >> b >> c;
    for (int i = 0; i < a; i++){
        if (i < b || i > c){
            cout << arr[i] << " ";
        }
    }
    return 0;
}