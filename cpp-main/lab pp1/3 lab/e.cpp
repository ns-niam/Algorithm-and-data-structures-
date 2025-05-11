#include <bits/stdc++.h>
using namespace std;
int main() {
    int c;
    cin>>c;

    long long d=0;
    long long a[c];
    for (int i=0;i<c;i++){
        cin>>a[i];
        d=d+a[i];
    }
    cout<<d;
    }
    