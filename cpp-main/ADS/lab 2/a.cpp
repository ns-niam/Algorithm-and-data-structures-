#include <bits/stdc++.h>

using namespace std;

int main(){
    int m; 
    cin >> m;
    vector<int> v(m);
    int find_num;
    
    for(int i = 0; i < m; i++) {
        cin >> v[i];
    }
    
    cin >> find_num;
    
    int min1 = INT_MAX;
    int min_index = -1; 
    
    for(int i = 0; i < m; i++) {
        int diff = abs(v[i] - find_num);
        if(diff < min1) {
            min1 = diff;
            min_index = i;
        }
    }
    
    cout << min_index << endl; 
    return 0;
}