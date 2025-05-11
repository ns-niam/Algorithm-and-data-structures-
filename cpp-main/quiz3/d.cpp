#include <bits/stdc++.h>

using namespace std;

char change(int n){
    if(n >= 10)
        return 'A' + n - 10; 
    return n + '0';
}

void hex(int n){
    if(n == 0) return;
    hex(n / 16);
    cout << change(n % 16);
}

int main(){
    int n;
    cin >> n;
    hex(n);
    return 0;
}