#include <bits/stdc++.h>

using namespace std;

long long joke (int n){
    long long sum = 1;
    for (int i = 1; i <= n; i++){
        sum = sum * i;
    }
    return sum;
}
int main (){
    int a;
    cin >> a;
    cout << joke(a);
    return 0;
}