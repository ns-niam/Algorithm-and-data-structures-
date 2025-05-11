#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    priority_queue<long long, vector<long long>, greater<long long>> minHeap(ar.begin(), ar.end());

    long long answer = 0;
    while (minHeap.size() > 1) {
        long long first = minHeap.top();
        minHeap.pop();
        long long second = minHeap.top();
        minHeap.pop();
        answer += first + second;
        minHeap.push(first + second);
    }

    cout << answer << endl;

    return 0;
}