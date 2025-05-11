#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    int findSet(int v) {
        if (v != parent[v])
            parent[v] = findSet(parent[v]);
        return parent[v];
    }

    void uniteSets(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (rank[a] < rank[b]) 
                swap(a, b);
            
            parent[b] = a;

            if (rank[a] == rank[b]) 
                ++rank[a];
        }
    }
};

class Graph {
private:
    vector<pair<int, pair<int, int>>> edges;
    int numVertices;

public:
    Graph(int n) : numVertices(n) {}

    void addEdge(int u, int v, int weight) {
        edges.emplace_back(weight, make_pair(u, v));
    }

    int kruskalMST() {
        sort(edges.begin(), edges.end());
        DisjointSet ds(numVertices);

        int totalCost = 0;
        vector<pair<int, int>> resultEdges;

        for (const auto& edge : edges) {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (ds.findSet(u) != ds.findSet(v)) {
                totalCost += weight;
                resultEdges.push_back({u, v});
                ds.uniteSets(u, v);
            }
        }
        return totalCost;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> elements(n);
    for (int i = 0; i < n; ++i)
        cin >> elements[i];

    Graph graph(n);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int weight = elements[i] + elements[j];
            graph.addEdge(i, j, weight);
        }
    }

    int totalCost = graph.kruskalMST();
    cout << totalCost << endl;

    return 0;
}