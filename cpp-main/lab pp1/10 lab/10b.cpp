#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++){
        
        string s = to_string(powl(i, i));

        for (int j = s.size(); 0 < j; j--){
            if(s[j - 1] == '.') {
                s.erase(j - 1, 1);
                break;
            }

            else if(s[j-1] == '0') 
                s.erase(j-1, 1);
        }
        cout << s << " ";
    }
    return 0;
}