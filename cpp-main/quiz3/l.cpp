#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(std::cin, s);
    for(auto c : s){
        if (isalpha(c)){
            if (c != 'z' || c != 'Z')
                c += 1;
            else if (c == 'Z')
                c = 'A';
            else if (c == 'z')
                c = 'a';
        }
        cout << c;
    }
    return 0;
}