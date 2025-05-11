#include <bits/stdc++.h>
using namespace std;
int main() {
    int c;
    cin>>c;
    int s=-1000000;
    int a[c];
    for (int i=0;i<c;i++){
        cin>>a[i];
        s=max(a[i],s);
    }
    cout<<s;
    }
    