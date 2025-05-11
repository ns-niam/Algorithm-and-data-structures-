#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, c;
    cin >> n >> c;
    vector <int> v;
    vector <int> ac;
    for (int i = 0; i < n; i++){
        int s;
        cin >> s;
        v.push_back(s);
    }

    vector <int>::iterator it = unique(v.begin(), v.begin() + n);
    v.resize(distance(v.begin(), it));

    for (int i = 0; i < c; i++){
        int d;
        cin >> d;
        ac.push_back(d);
    }

    vector <int>::iterator it2 = unique(ac.begin(), ac.begin() + c);
    ac.resize(distance(ac.begin(), it2));
    int size = v.size() + ac.size();
    vector <int> ans (size);

    for (int i = 0; i < size; i += 2){
        ans[i] = v[i/2];
    }
    for (int i = 1; i < size; i += 2){
        ans[i] = ac[i/2];
    }
    
    vector <int>::iterator i1 = unique(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), i1));
    for(i1 = ans.begin(); i1 != ans.end(); i1++){
        cout << *i1 << " ";
    }
    return 0;
}