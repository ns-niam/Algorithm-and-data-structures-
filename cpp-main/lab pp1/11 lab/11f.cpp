#include <bits/stdc++.h>

using namespace std;

int main (){
    int ernur, bekzat, zhasik;
    cin >> ernur >> bekzat >> zhasik;
    vector <int> v;
    for (int i = 1; i <= ernur && i <= bekzat; i++){
        if(ernur % i == 0 && bekzat % i == 0) v.push_back(i);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++){
        if(zhasik - 1 == i) cout << v[i] << endl;
    }
    return 0;
}