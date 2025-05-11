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
    int numVertices;
    vector<pair<int, pair<int, int>>> edges;

public:
    Graph(int n) : numVertices(n) {}

    void addEdge(int cost, int cityA, int cityB) {
        edges.emplace_back(cost, make_pair(cityA, cityB));
    }

    int kruskalMST() {
        sort(edges.begin(), edges.end()); 
        DisjointSet ds(numVertices);

        int totalCost = 0;
        vector<pair<int, int>> selectedEdges;

        for (const auto& edge : edges) {
            int cost = edge.first;
            int cityA = edge.second.first;
            int cityB = edge.second.second;

            if (ds.findSet(cityA) != ds.findSet(cityB)) {
                totalCost += cost;
                selectedEdges.push_back({cityA, cityB});
                ds.uniteSets(cityA, cityB);
            }
        }

        return totalCost;
    }
};

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    Graph graph(n);

    while (m--) {
        string roadType;
        int cityA, cityB, cost;
        cin >> roadType >> cityA >> cityB >> cost;

        if (roadType == "big") {
            graph.addEdge(cost * x, cityA - 1, cityB - 1);
        } else if (roadType == "small") {
            graph.addEdge(cost * y, cityA - 1, cityB - 1);
        } else if (roadType == "both") {
            graph.addEdge(cost * x, cityA - 1, cityB - 1);
            graph.addEdge(cost * y, cityA - 1, cityB - 1);
        }
    }

    int totalCost = graph.kruskalMST();
    cout << totalCost << endl;

    return 0;
}
