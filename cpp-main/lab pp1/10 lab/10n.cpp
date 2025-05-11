#include <bits/stdc++.h>

using namespace std;

bool compare (vector <int> a){
    for (int i = 0; i < a.size() / 2; i++){
        if (a[i] != a[a.size() - 1 - i]) return false;
    }
    return true;
}

int main (){
    int n;
    vector <int> v;
    cin >> n;
    for (int i = 0; i < n; i++){
        int s; 
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    do{
        if(compare(v)){
            for (int i = 0; i < v.size(); i++){
                cout << v[i] << " ";
            }
            return 0;
        }
    }
    while(next_permutation(v.begin(),v.end()));
    cout << "Impossible";
    return 0;
}