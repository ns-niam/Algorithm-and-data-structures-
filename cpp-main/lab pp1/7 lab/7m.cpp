#include <bits/stdc++.h>

using namespace std;

void joke (int a){
    for (int i = 0; i < a; i++){
        cout << i + 1 << " ";
    }
}

int main (){
    int n;
    cin >> n;
    joke (n);
    return 0;
}