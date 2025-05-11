#include <bits/stdc++.h>
using namespace std;
int main() {
    int m,n;
    cin>>m;
    for(int i=1;i<m;i++){
      if(m%i==0) n++;
    }if (n<=2) {cout<<"Yes";}
    else {cout<<"No";}
    return 0;
}