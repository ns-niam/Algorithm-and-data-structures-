#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll bs(ll left, ll right, ll target, ll a[]){
    ll ans;
    if (target < a[0])
        return 0;
    else if (target >= a[right])
        return right + 1;
    else{
        while (left <= right){
            ll mid = left + (right - left) / 2;
            if (a[mid] <= target){
                left = mid + 1;
                ans = mid;
            } else right = mid - 1;
        }
        return ans + 1;
    }
}

int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll test;
    cin >> test;
    ll x, sum = 0;
    sort(arr, arr + n);
    while (test--){
        cin >> x;
        ll new_size = bs(0, n - 1, x, arr);

        for (ll i = 0; i < new_size; i++)
            sum += arr[i];
        cout << new_size << ' ' << sum << endl;
        sum = 0;
    }
    return 0;
}