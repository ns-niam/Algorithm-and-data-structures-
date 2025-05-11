#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int n;
    cin >> s >> n;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i]) == true){
          cnt++;
        }
    }
    if( cnt < n ){
        cout<<"NO";
        return 0;
    }
    else{
        cout<<"YES";
    }
    return 0;
}