#include <bits/stdc++.h>
#include <map>
using namespace std;

int main (){
    int n, cnt = 0;
    vector <string> da;
    cin >> n;
    for (int i = 0; i < n; i++){
        string d;
        cin >> d;
        da.push_back(d);
        if (count(da.begin(), da.end(), d) == 3) {
            cnt++;
        }
        else if (count(da.begin(), da.end(), d) == 4){
            cnt--;
            da.erase(da.begin(), da.end());
        }
    }
    
    cout << cnt << endl;
    return 0;
}