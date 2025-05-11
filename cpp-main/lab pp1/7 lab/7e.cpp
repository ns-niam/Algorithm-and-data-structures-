#include <bits/stdc++.h>

using namespace std;

string joke (long long s){
    int n = 0;
    while (pow(2,n) != s){
        n++;
        if ( n == 100) break;
    }
    if (pow(2,n) == s) return "Yes";
    else return "No";
}
int main(){
    long long n;
    cin >> n;
    cout <<joke(n); 
}