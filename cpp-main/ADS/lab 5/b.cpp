#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    priority_queue<long long> maxHeap(arr.begin(), arr.end());

    long long answer = 0;
    while (maxHeap.size() > 1) {
        long long first = maxHeap.top();
        maxHeap.pop();
        long long second = maxHeap.top();
        maxHeap.pop();
        
        if (first != second) {
            answer = first - second;
            maxHeap.push(answer);
        }
    }

    int result = (maxHeap.size() == 1) ? maxHeap.top() : 0;
    cout << result << endl;

    return 0;
}