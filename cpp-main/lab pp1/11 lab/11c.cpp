#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    double sum;
    map<string, int> mp;
    for (int i = 0; i < n; i++){
        string students;
        int score;
        cin >> students >> score;
        mp[students] += score;
        sum += score;
    }
    map <string, int>::iterator it;
    vector <pair<int, string>> v;
    for (it = mp.begin(); it != mp.end(); it++){
        v.push_back(make_pair((*it).second,(*it).first));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i].second << " " << (double) v[i].first * 100 / sum << "%" <<  endl;
    }
    return 0;
}