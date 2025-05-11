#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(std::cin, s);
    int sum = 0;
    for(auto c : s) sum += c;
    cout << (sum > 300 ? "TASTY" : "OK") << endl;
    return 0;
}