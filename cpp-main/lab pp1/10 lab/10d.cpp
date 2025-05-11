#include <bits/stdc++.h>

using namespace std;

bool compare (vector<int> a, vector<int> b){
    int sum = 0, sum1 = 0;
    for (int i = 0; i < a.size(); i++){
        sum += a[i];
    }
    for (int i = 0; i < b.size(); i++){
        sum1 += b[i];
    }
    if (sum < sum1) return true;
    else return false;
}

int main (){
    vector<int> v;
    vector<vector<int>> vv;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        for (int j = 0; j < m; j++){
            int c;
            cin >> c;
            v.push_back(c);
        }
        vv.push_back(v);
        v.clear();
    }

    sort(vv.begin(), vv.end(),compare);

    for (int i = 0; i < vv.size(); i++){
        for (int j = 0; j < vv[i].size(); j++){
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}