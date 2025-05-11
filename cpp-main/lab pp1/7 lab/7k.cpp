#include <bits/stdc++.h>

using namespace std;

int joke (){
    string s;
    cin >> s;
    int max1 = INT_MIN;
    for (auto c : s){
        max1 = max(max1, c - '0');
    }
    return max1;
}

int main (){
    cout << joke ();
    return 0;
}