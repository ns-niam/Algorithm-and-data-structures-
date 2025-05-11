#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    int g[n][n];
    vector<bool> visited(n, false);
    vector<int> parent(n, -1), minEdge(n, INF);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    minEdge[0] = 0;

    int totalWeight = 0;

    for (int i = 0; i < n; i++) {
        int currentVertex = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (currentVertex == -1 || minEdge[j] < minEdge[currentVertex])) {
                currentVertex = j;
            }
        }

        visited[currentVertex] = true;

        if (parent[currentVertex] != -1) {
            totalWeight += g[currentVertex][parent[currentVertex]];
        }

        for (int j = 0; j < n; j++) {
            if (g[currentVertex][j] < minEdge[j]) {
                minEdge[j] = g[currentVertex][j];
                parent[j] = currentVertex;
            }
        }
    }

    cout << totalWeight;

    return 0;
}

