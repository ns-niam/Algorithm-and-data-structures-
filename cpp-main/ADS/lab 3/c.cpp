#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k, a[100001], i, j;
int l1, r1, l2, r2;
int bs(int p, char ch){
    int l = 0;
    int r = n - 1;
    int mid;
    while (l <= r){
        mid = (l + r) / 2;
        if (a[mid] == p)
            return mid;
        else if (a[mid] < p)
            l = mid + 1;
        else if (a[mid] > p)
            r = mid - 1;
    }
    if (ch == 'l')
        return l;
    else
        return r;
}
int pos(int l, int r){
    return bs(r, 'r') - bs(l, 'l') + 1;
}
int main(){
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < k; i++){
        cin >> l1 >> r1 >> l2 >> r2;
        if (l1 <= l2 && r2 <= r1)
            cout << pos(l1, r1) << endl;
        else if (l2 <= l1 && r1 <= r2)
            cout << pos(l2, r2) << endl;
        else if (r2 >= l1 && r1 >= r2 && l1 >= l2)
            cout << pos(l2, r1) << endl;
        else if (r1 >= l2 && r2 >= r1 && l2 >= l1)
            cout << pos(l1, r2) << endl;
        else
            cout << pos(l1, r1) + pos(l2, r2) << endl;
    }
}