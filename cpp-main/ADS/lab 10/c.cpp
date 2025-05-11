// Problem C: Aho-Corazick
// You are given two numbers 
//  and 
// .

// You can do one of the operations with 
//  in each turn.

// Multiply number by 2.

// Decrease the number by 1.

// You need to find the minimum number of operations, to make 
//  equal to 
// .

// Also print the every element after doing the operation.

// Input format
// In the first line given two integers 
// , 
//  where 
// .

// Output format
// Print one integer 
//  the minimum number of operations. In the second line print m integers, number after every operation.

// Examples
// Input
// 5 9
// Output
// 2
// 10 9 


#include <bits/stdc++.h>

using namespace std;

unordered_set<int> visitedNumbers;
queue<pair<int, int>> processQueue;
vector<int> path;

int bfs(int currentValue, int currentDistance, int targetValue) {
    if (currentValue == targetValue) return currentDistance;

    visitedNumbers.insert(currentValue);
    path.push_back(currentValue);

    int nextValue = -1;

    if (currentValue % 2 == 1 && visitedNumbers.find(currentValue / 2 + 1) == visitedNumbers.end() && targetValue < currentValue) {
        nextValue = (currentValue + 1) / 2;
        path.push_back(currentValue + 1);
    } else if (currentValue % 2 == 0 && visitedNumbers.find(currentValue / 2) == visitedNumbers.end() && targetValue < currentValue) nextValue = currentValue / 2;

    if (visitedNumbers.find(currentValue + 1) == visitedNumbers.end() && targetValue > currentValue) nextValue = currentValue + 1;

    processQueue.push({nextValue, currentDistance + 1});
    return -1;
}

int main() {
    int startValue, targetValue, resultDistance = -1;
    cin >> startValue >> targetValue;

    processQueue.push({targetValue, 0});

    while (!processQueue.empty()) {
        pair<int, int> current = processQueue.front();
        int currentValue = current.first, currentDistance = current.second;
        processQueue.pop();

        resultDistance = bfs(currentValue, currentDistance, startValue);

        if (resultDistance != -1) break;
    }

    if (path.size() > resultDistance) cout << path.size() << endl;
    else cout << resultDistance << endl;

    if (path.size() > 0)
        for (int i = path.size() - 1; i >= 0; i--)
            cout << path[i] << " ";

    return 0;
}
