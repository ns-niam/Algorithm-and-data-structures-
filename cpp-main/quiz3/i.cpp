#include <bits/stdc++.h>

using namespace std;

int main(){
    string d, s;
    getline(std::cin, d);
    cin >> s;
    char g;
    cin >> g;
    vector<char> v;
    for(auto c : s)
        v.push_back(c);
    for(auto c : d)
        if(find(v.begin(), v.end(), c) == v.end())
            cout << c;
        else
            cout << g;
    return 0;
}