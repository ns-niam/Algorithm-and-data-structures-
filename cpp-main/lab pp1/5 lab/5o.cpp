#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1;
    cin>>s1;
    int max=s1[0];
    for(int i=0;i<s1.size();i++){
        if(max<s1[i]){
            max=s1[i];
        }
    }
    cout<<(char)max;
}