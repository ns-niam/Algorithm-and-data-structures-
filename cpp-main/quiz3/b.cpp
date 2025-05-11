#include <bits/stdc++.h>

using namespace std;

int main(){
    char d;
    string s;
    cin >> d >> s;
    for(auto c : s)
        if(c != d) 
            cout << c;
    return 0;
}