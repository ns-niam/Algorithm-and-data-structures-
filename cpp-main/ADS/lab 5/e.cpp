#include <bits/stdc++.h>

using namespace std;

int main() {
    long long sum = 0, n, k, num;
    cin >> n >> k;
    string command;
    
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    while (n--) {
        cin >> command;
        
        if (command == "print")
            cout << sum << endl;
        
        if (command == "insert") {
            cin >> num;
            minHeap.push(num);

            if (minHeap.size() > k) {
                long long min = minHeap.top();
                minHeap.pop();
                if (num > min) {
                    sum -= min;
                    sum += num;
                } else {
                    minHeap.push(min);
                    minHeap.pop();
                }
            } else {
                sum += num;
            }
        }
    }

    return 0;
}