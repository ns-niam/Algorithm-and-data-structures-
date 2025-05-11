#include <bits/stdc++.h>

using namespace std;

int vowel (char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return 1;
    }
    return 0;
}

int main (){
    string s;
    int cnt = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        cnt += vowel(s[i]);
    }
    cout << cnt << endl;
}