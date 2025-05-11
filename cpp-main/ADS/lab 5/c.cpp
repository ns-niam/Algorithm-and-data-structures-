#include <bits/stdc++.h>

using namespace std;


int main() {
    long long n, x, sum = 0;
    cin >> n >> x;
    vector<long long> arr(n);
    
    for (long long i = 0; i < n; i++)
        cin >> arr[i];

    priority_queue<long long> maxHeap(arr.begin(), arr.end());

    while (x--) {
        long long seat = maxHeap.top();
        maxHeap.pop();
        sum += seat;
        seat--;
        maxHeap.push(seat);
    }

    cout << sum << endl;

    return 0;
}