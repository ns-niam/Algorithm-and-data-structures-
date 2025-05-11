#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int m; cin >> m;
    int b[m];
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    int k = n + m;
    int c[k];
    int l = 0, r = 0;
    int p = 0;
    while(l < n && r < m){
        if(a[l] < b[r]){
            c[p++] = a[l++];
        }
        else{
            c[p++] = b[r++];
        }
    }
    for(; l < n; l++){
        c[p++] = a[l];
    }
    for(; r < m; r++){
        c[p++] = b[r];
    }

    for(int i = 0; i < k; i++) 
        cout << c[i] << " ";
    
    return 0;
}