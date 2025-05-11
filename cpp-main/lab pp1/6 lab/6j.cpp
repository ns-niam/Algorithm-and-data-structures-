#include <bits/stdc++.h>

using namespace std;

int joke(int a, int b,int c,int d ){
    return max(a,max(b,max(c,d)));
}

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<joke(a,b,c,d);
    return 0;
}