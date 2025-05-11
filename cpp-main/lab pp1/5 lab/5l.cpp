#include <bits/stdc++.h>

using namespace std;

int main(){
    string Stringi;
    cin >> Stringi;
    for (int i = 0; i < Stringi.size() - 1 ; i++){    
        int c = Stringi [i];
        int d = Stringi [ i + 1 ];
        if( c > d ){
        cout << "NO";
        return 0;
        }
    }
    cout << "YES";
    return 0;
}