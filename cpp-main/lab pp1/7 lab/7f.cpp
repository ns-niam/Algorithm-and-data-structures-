#include <bits/stdc++.h>

using namespace std;

int joke (string s){
    int even = 0;
    for (auto c : s){
        if (c == '2') even++;
        else if (c == '4') even++;
        else if (c == '8') even++;
        else if (c == '6') even++;
        else if (c == '0') even++;
    }
    return even;
}
int main (){
    string s;
    getline(cin,s);
    cout << joke(s);
    return 0;
}