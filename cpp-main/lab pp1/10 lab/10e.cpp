#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    map <string, double> hoho;
    double all;
    for (int i = 0; i < n; i++){
        int xo;
        cin >> xo;
        for (int j = 0; j < xo; j++){
            string name;
            cin >> name;
            double price;
            cin >> price;
            hoho[name] += price;
            all += price;
        }
    }
    for (auto i : hoho){
        cout << i.first << " " << i.second * 100 / all << endl;
    }
    return 0;
}