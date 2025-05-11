#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n];
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    for (int i = 0; i < n; i++){
      if (max < a[i]){
        max = a[i];
      }
      if (min > a[i]){
        min = a[i];
      }
    }
    for (int i = 0; i < n; i++){
      if (a[i] == max){
      a[i] = min;
      }
    }
    for (int i = 0; i < n; i++){
      cout << a[i] << ' ';
      
    }
    return 0;
}