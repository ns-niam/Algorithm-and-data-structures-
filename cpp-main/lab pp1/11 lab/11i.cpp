#include <bits/stdc++.h>

using namespace std;

bool palindrome(string kama){
    for(int i = 0; i < kama.size() / 2; i++){
        if(kama[i]!=kama[kama.size() - i - 1]) return false;
    }
    return true;
}

int main (){
    string kama;
    cin >> kama;
    sort(kama.begin(), kama.end());
    bool apai = false;
    do{
        if(palindrome(kama)){
            apai = true;
            break;
        }
    }
    while(next_permutation(kama.begin(), kama.end()));
    if (apai) cout << "ZA WARUDO TOKI WO TOMARE";
    else cout << "JOJO";
}