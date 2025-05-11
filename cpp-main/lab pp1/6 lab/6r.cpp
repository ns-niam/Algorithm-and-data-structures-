#include <bits/stdc++.h>

using namespace std;

void joke (string o){
    for (auto i : o){
        if (i <= 'z' && i >= 'a'){
            i = (int) i - 32 ;
        }
        cout << i;
    }    
    return;
} 
int main(){
    string s;
    getline(cin,s);
    joke(s);
    return 0;
}