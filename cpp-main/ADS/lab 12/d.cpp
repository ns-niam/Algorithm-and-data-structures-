#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 200005;
const int INF = 2000000007;

int x[MAX_NODES], y[MAX_NODES];
int parent[MAX_NODES];
int minRadius = 0;

int findRoot(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findRoot(parent[node]);
}

bool unionSets(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) return false;
    if (rand() % 2) swap(a, b);
    parent[b] = a; 
    return true;
}

void findMinRadius(int left, int right, int nodeCount) {
    while (left <= right) {
        int mid = (left + right) / 2;

        for (int i = 1; i <= nodeCount; i++) parent[i] = i;

        for (int i = 1; i <= nodeCount; i++) {
            for (int j = 1; j <= nodeCount; j++) {
                int distance = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                if (distance <= mid) {
                    unionSets(i, j);
                }
            }
        }

        if (findRoot(1) == findRoot(nodeCount)) {
            minRadius = mid;
            right = mid - 1;
        } else {
            left = mid + 1; 
        }
    }
}

int main() {
    int nodeCount;
    cin >> nodeCount;
    for (int i = 1; i <= nodeCount; i++)
        cin >> x[i] >> y[i];
    findMinRadius(0, INF, nodeCount);
    cout << minRadius;
    return 0;
}
