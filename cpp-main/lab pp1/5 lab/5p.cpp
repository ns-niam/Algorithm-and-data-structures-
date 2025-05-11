#include <bits/stdc++.h>

using namespace std;

int main (){
    string s;
    getline ( cin, s );
    for ( auto c : s){
        if ( c == 'z' ){
            c = 'a';
        } else {
            c = (int) c + 1 ;
        }
        cout << c;
    }    
}