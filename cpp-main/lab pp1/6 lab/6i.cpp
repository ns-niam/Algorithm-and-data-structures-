#include <bits/stdc++.h>

using namespace std;

string joke(string n){
   for(int i=0;i<n.size();i++){
    if(i%2==0){
        n[i] = toupper(n[i]);
    }
   }
   return n;
}

int main(){
    string n;
    cin >> n;
    cout << joke(n) << endl;
    return 0;
}