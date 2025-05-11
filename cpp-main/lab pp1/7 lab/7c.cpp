#include <bits/stdc++.h>

using namespace std;

string joke (){
    int a;
    cin >> a;
    int arr [a];
    for (int i = 0; i < a; i++){
        cin >> arr[i];
    }
    int b;
    cin >> b;
    for (int i = 0; i < a; i++){
        if (arr[i] == b){
            return "Yes";
        }
    }
    return "No";
}
int main (){
    cout << joke ();
    return 0;
}