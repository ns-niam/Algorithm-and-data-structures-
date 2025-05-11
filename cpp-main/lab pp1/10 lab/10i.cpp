#include <bits/stdc++.h>

using namespace std;

int main (){
    int a;
    cin >> a;
    int n [a];
    for (int i = 0; i < a; i++){
        cin >> n[i];
    }
    int n2[a];
    for (int i = 0; i < a; i++){
        n2[i] = n[i];
    }
    reverse(n2, n2 + a);
    for (int i = 0; i < a; i++){
        if (n[i] != n2[i]){
            cout << "Instead of " << n[i] << " here was " << n2[i] << endl;
        }
        else if (n[i] == n2[i]){
            cout << "OK" << endl;
        }
    }
    return 0;
}