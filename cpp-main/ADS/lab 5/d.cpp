#include <bits/stdc++.h>

using namespace std;

int main() {
    bool flag = false;
    long long n, m, cnt = 0, new_element = 0;
    cin >> n >> m;
    vector<long long> arr(n);
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    priority_queue<long long, vector<long long>, greater<long long>> minHeap(arr.begin(), arr.end());

    while (minHeap.size() > 1) {
        long long first = minHeap.top();
        minHeap.pop();
        if (first >= m) {
            flag = true;
            break;
        }
        long long second = minHeap.top();
        minHeap.pop();
        new_element = first + 2 * second;
        minHeap.push(new_element);
        cnt++;
        if (new_element >= m)
            flag = true;
    }

    if (flag)
        cout << cnt;
    else
        cout << -1;

    return 0;
}