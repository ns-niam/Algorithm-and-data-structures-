#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while(cin >> s){
        bool a = true;
        for(auto c : s)
            if (isdigit(c)) {
                a = false;
                break;
            }
        if (a) {
            cout << s << "\n";
        }
    }
    return 0;
}