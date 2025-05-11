#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
    vector<int> parent, leftmost, rightmost;

public:
    UnionFind(int n) {
        parent.resize(n);
        leftmost.resize(n);
        rightmost.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            leftmost[i] = i;
            rightmost[i] = i;
        }
    }

    int find(int i) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unionSets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return;
        }

        parent[a] = b;
        leftmost[b] = min(leftmost[a], leftmost[b]);
        rightmost[b] = max(rightmost[a], rightmost[b]);
    }

    int getLeftmost(int i) {
        return leftmost[find(i)];
    }

    int getRightmost(int i) {
        return rightmost[find(i)];
    }
};

class Solution {
private:
    int n, m;
    vector<pair<int, pair<int, int>>> edges;

public:
    Solution(int nodes, int edgesCount) : n(nodes), m(edgesCount) {}

    void addEdge(int l, int r, int cost) {
        edges.push_back({cost, {l - 1, r - 1}});
    }

    long long computeMinimumCost() {
        sort(edges.begin(), edges.end());
        UnionFind uf(n);

        long long totalCost = 0;
        int components = 0;

        for (const auto& edge : edges) {
            if (components >= n - 1) {
                break;
            }

            int left = edge.second.first;
            int right = edge.second.second;
            int cost = edge.first;

            int representative = uf.find(left);

            if (uf.getLeftmost(representative) <= left && right <= uf.getRightmost(representative)) {
                continue;
            } else if (uf.getLeftmost(representative) <= right && right <= uf.getRightmost(representative)) {
                right = uf.getLeftmost(representative);
            } else if (uf.getLeftmost(representative) <= left && left <= uf.getRightmost(representative)) {
                left = uf.getRightmost(representative);
            }

            for (int j = left; j <= right; j++) {
                if (uf.find(representative) != uf.find(j)) {
                    uf.unionSets(representative, j);
                    components++;
                    totalCost += cost;
                }
            }
        }

        return totalCost;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Solution solution(n, m);

    for (int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        solution.addEdge(l, r, c);
    }

    cout << solution.computeMinimumCost() << endl;

    return 0;
}