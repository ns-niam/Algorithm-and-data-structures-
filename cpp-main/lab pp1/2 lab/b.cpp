#include <iostream>
using namespace std;
int main (){
    int a;
    cin>>a;
    if (a%2==1){
        cout<<"Super";
    }else if(2<=a&&a<=5){
            cout<<"Not Super";
        }else if(6<=a&&a<=20){
            cout<<"Super";
        }else {
            cout <<"Not Super";
        }
    return 0;
}
