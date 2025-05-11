#include <bits/stdc++.h>

using namespace std;

int joke (){
    int n;
    int sum = 0;
    while (cin >> n){
        if (n == 0){
            break;
        }
        sum += n;
    }
    return sum;
}
int main(){
    cout << joke();
    return 0;
}