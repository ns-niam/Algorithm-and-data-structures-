#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(std::cin, s);
    for(auto c : s)
        if (isalpha(c))
            cout << c;
    return 0;
}