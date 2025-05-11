
#include <iostream>
using namespace std;
int main(){
   int n;
   int b=0;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
      cin>>a[i];
      if(a[i]%10==7){
         b++;
      }
   }cout<<b<<endl;
   return 0;
}
