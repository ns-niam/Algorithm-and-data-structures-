#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check(ll n, ll cur, ll arr[][4], ll k){
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
        if (cur > max(arr[i][3], arr[i][2]))
            cnt++;
    return cnt >= k;
}

ll ans(ll left, ll right, ll n, ll arr[][4], ll k){
    ll answer;
    while (left <= right){
        ll mid = left + (right - left) / 2;
        if (check(n, mid, arr, k)){
            answer = mid;
            right = mid - 1;
        }else left = mid + 1;
    }
    return answer;
}

int main(){
    ll n, k;
    cin >> n >> k;
    ll arr[n][4];
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < 4; j++)
            cin >> arr[i][j];
    cout << ans(0, pow(10, 10), n, arr, k) - 1;
}