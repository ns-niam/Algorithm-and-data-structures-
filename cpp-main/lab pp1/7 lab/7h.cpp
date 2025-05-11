#include <bits/stdc++.h>

using namespace std;

int joke (int a){
    int num1 = 0;
    int num2 = 1;
    int num_next = 1;
    if (a == 1)
        return 0;
    if (a == 2)
        return 1;
    for (int i = 0; i < a - 2; i++){
        num_next = num1 + num2;
        num1 = num2;
        num2 = num_next;
    }
    return num_next;
}

int main (){
    int n;
    cin >> n;
    cout << joke(n);
    return 0 ;
}