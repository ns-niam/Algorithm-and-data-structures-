#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int a, w = 0;
    cin >> s >> a;
    for( int i = 0; i < s.size(); i++ ){
        if (isdigit(s[i])){
            w++;
            if (w == a){
               cout << "Valid"; 
               return 0;
            }
        }
        else {
            w = 0;
        }
    }
     if ( w!= a ) cout << "Not valid";
    return 0;
}