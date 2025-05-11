#include <bits/stdc++.h>
using namespace std;
int main() {
    int c;
    cin>>c;
    int s=0;
    int a[c];
    for (int i=0;i<c;i++){
        cin>>a[i];
        if(a[i]>0){
            s++;
        }
    }
    cout<<s;
    }
    