#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;
    char t;
    cin >> s >> t;
    bool k=0, z=0;
    int i1, i2;
    for(int i=0; i<s.size(); i++){
        if(z==0 && t==s[i]){
            i1=i;
            z=1;
        }
        else if(t==s[i]){
            k=1;
            i2=i;
        }
    }
    if(k==1){
        cout<<i1<<" "<<i2;
    }
    else{
        cout<<i1;
    }
    return 0;
}