#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int maximum = 0, minimum = 9;
    
    for(auto i : s){
        maximum = max(maximum, (int)i - '0'); // max digit in string
        minimum = min(minimum, (int)i - '0'); // min digit in string
    }
    cout << maximum << " " << minimum << endl;
    return 0;
}