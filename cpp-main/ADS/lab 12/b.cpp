#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
class Graph {
private:
    vector<vector<pair<int, int>>> g;    // Список смежности (весовые рёбра)
    vector<int> d;                       // Вектор для хранения расстояний
    int n;                               // Количество вершин

public:
    Graph(int vertices) : n(vertices) {
        g.resize(n + 1);
        d.resize(n + 1, INF);
    }

    void addEdge(int a, int b, int c) {
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    int dijkstra(int start, int end) {
        d.assign(n + 1, INF);  
        d[start] = 0;

        set<pair<int, int>> q; 
        q.insert({0, start});

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (const auto& edge : g[v]) {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to]) {
                    q.erase({d[to], to});
                    d[to] = d[v] + len;
                    q.insert({d[to], to});
                }
            }
        }

        return d[end];
    }
};


int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.addEdge(a, b, c);
    }

    int q, w, e, r;
    cin >> q >> w >> e >> r;

    int path1 = graph.dijkstra(q, w) + graph.dijkstra(w, e) + graph.dijkstra(e, r);
    int path2 = graph.dijkstra(q, e) + graph.dijkstra(e, w) + graph.dijkstra(w, r);

    int result = min(path1, path2);

    if (result <= INF) {
        cout << result;
    } else {
        cout << -1;
    }

    return 0;
}
