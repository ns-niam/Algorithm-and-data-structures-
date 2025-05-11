#include <iostream>
#include <string>
using namespace std;

string a(string n){
    if(n == "0" ){
        return "false";
    }
        else if(n =="1"){
            return "true";
        }
        else{
            return n;
        }
}

int main(){
    string n;
    getline(cin, n);
    cout<<a(n);
    return 0;
}