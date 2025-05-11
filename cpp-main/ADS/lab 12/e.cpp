#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int a, b, cost;
};

int n;
vector<Edge> edges;
const int INF = 1e9;
bool cycle = false;
int v; 

void findNegativeCycle() {
    int x;
    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n, -1);

    for (int i = 0; i < n; i++) {
        x = -1;
        for (const auto &edge : edges) {
            if (d[edge.a] < INF) {
                if (d[edge.b] > d[edge.a] + edge.cost) {
                    d[edge.b] = max(-INF, d[edge.a] + edge.cost);
                    p[edge.b] = edge.a;
                    x = edge.b;
                }
            }
        }
    }

    if (x == -1) {
        cycle = false;
    } else {
        int y = x;
        for (int i = 0; i < n; i++) {
            y = p[y];
        }

        vector<int> path;
        for (int cur = y;; cur = p[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1) break;
        }

        reverse(path.begin(), path.end());

        cout << "YES\n" << path.size() << endl;
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] + 1 << ' ';
        }
        cout << endl;

        cycle = true;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Edge cur;
            cin >> cur.cost;
            cur.a = i;
            cur.b = j;
            edges.push_back(cur);
        }
    }

    for (int i = 0; i < n; i++) {
        v = i;
        findNegativeCycle();
        if (cycle) break;
    }

    if (!cycle)
        cout << "NO\n";

    return 0;
}
