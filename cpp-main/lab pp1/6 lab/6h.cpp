#include <bits/stdc++.h>

using namespace std;

string joke (int n){
    int s = 0;
    int a = n;
    while(n != 0){
        if ( (n % 10) % 2 == 0 ){
            s++;
        } else {
            break;
        }
        n /= 10;
    }
    int d = 0;
    while (a != 0){
        d++;
        a /= 10;
    }
    if ( s == d ){
        return "Valid";
    } else {
        return "Not valid";
    }
}
int main(){
    int a;
    cin >> a;
    cout << joke(a);
}