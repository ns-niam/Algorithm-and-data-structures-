#include <bits/stdc++.h>

using namespace std;

int string_shift(string shifting, string finding){
    if(shifting.size() != finding.size()) return -1;
    shifting += shifting;
    return (shifting.find(finding) != string::npos ? shifting.find(finding) : -1);
}

int main(){
    string A, B;
    cin >> B >> A;
    cout << string_shift(A, B) << endl;
    return 0;
}