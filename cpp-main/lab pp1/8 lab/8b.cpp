#include <bits/stdc++.h>

using namespace std;

int main (){
    int a;
    cin >> a;
    int v[a];
    for (int i = 0; i < a; i++){
        cin >> v [i];
    }
    reverse (v, v + a);
    for (int i = 0; i < a; i++){
        cout << v [i] << " ";
    }
    return 0;
}