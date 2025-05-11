#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a = 2 * n;
    if (a == k){
        cout << a / k + 1;
   } else {
        cout << (a + a % k) / k; 
    }
    return 0;
}