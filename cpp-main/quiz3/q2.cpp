#include <iostream>
#include <string>
#include <vector>
using namespace std;

string a(vector<string> v){
    for(int i=0; i<v.size(); i++){
        string k = v[i];
        k.erase(k.begin(), k.end()-10);
        if(k=="@gmail.com"){
            v[i].erase(v[i].end() - 10, v[i].end());
            cout << v[i];
        }
    }
    return " ";
}

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    a(v);
    return 0;
}