#include <bits/stdc++.h>
using namespace std;
int main() {        
    int n;
    cin>>n;
    int a[n];
    int maxi = -100000000000001;
    int index = 0;
    for(int i = 0; i < n; i++){
        cin>> a[i];
        if(a[i] > maxi){
            maxi = a[i];
            index = i + 1;
        } 
    }
    cout << index;
    return 0; 
    }
    