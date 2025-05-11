#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    pair <int, int> sum [n];
    pair <int, int> a [n];
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        sum[i] = make_pair(a[i].first + a[i].second, i + 1);
    }
    sort(sum, sum + n);
    for (int i = 0; i < n; i++){
        cout << sum[i].second << " ";
    }
    return 0;
}