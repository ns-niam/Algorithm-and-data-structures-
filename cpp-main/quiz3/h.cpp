#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int min1 = INT_MAX;
    string s = "";
    map<int, string> map;
    for(int i = 0; i < n; i++){
        string d;
        int e, r;
        cin >> d >> e >> r;
        map[e / r] = d;
    }
    int cnt = 0;
    for(auto it : map){
        min1 = min(min1, it.first);
        if(min1 == it.first && cnt++ < 1)
            s = it.second;
        else 
            cnt = 0;
    }
    cout << s << endl;
    return 0;
}