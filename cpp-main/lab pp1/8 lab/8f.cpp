#include <bits/stdc++.h>

using namespace std;

int main (){
    int a;
    cin >> a;
    int arr[ a + 1 ];
    for (int i = 0; i < a; i++){
        cin >> arr[i];
    }
    int c, b;
    cin >> c >> b;
    for (int j = 0; j < a; j++){
        if (j == c) cout << b << " ";
        cout << arr[j] << " ";
    }
    return 0;
}