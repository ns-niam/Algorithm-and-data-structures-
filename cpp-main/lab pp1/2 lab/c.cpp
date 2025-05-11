#include <iostream>
using namespace std;
int main (){
int a;
cin>>a;
cout<<((a%4==0)||(a%400==0)?"YES":"NO");
}