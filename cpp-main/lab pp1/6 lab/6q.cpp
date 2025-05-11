#include <bits/stdc++.h>

using namespace std;

void joke (int i, int s){
    float j = (float) s * 100 / i;
    cout << j;
    return;
}
int main(){
    int a, c;
    cin >> a >> c;
    joke (a, c);
    return 0;
}