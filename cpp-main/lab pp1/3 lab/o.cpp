#include <bits/stdc++.h>
using namespace std;
int main() {
    int m,n=0,c=0;
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        n = i;
        for (c=i;c<m;c++){
            if (a[n]<a[c]){
                n=c;
            }
        }
        swap(a[i],a[n]);
    }for(int i=0;i<m;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}