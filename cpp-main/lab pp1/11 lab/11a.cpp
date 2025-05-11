#include <bits/stdc++.h>

using namespace std;

map<string, int> map_string = {
    {"SAT", 1},
    {"MON", 6},
    {"TUE", 5},
    {"WED", 4},
    {"THU", 3},
    {"FRI", 2},
    {"SUN", 7},
};

int main (){
    string s;
    cin >> s;
    cout << map_string[s] << endl;
    return 0;
}