#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 410;
vector<int> roadGraph[MAX_NODES];
vector<int> airGraph[MAX_NODES];
int roadMatrix[MAX_NODES][MAX_NODES];

void findShortestPaths(vector<int> &distances, vector<bool> &visited, vector<int> graph[]) {
    queue<int> nodesQueue;
    nodesQueue.push(0);
    visited[0] = true;

    while (!nodesQueue.empty()) {
        int currentNode = nodesQueue.front();
        nodesQueue.pop();

        for (int i = 0; i < graph[currentNode].size(); i++) {
            int neighbor = graph[currentNode][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                nodesQueue.push(neighbor);
                distances[neighbor] = distances[currentNode] + 1;
            }
        }
    }
}

int main() {
    int totalNodes, totalEdges;
    cin >> totalNodes >> totalEdges;

    for (int i = 0; i < totalEdges; i++) {
        int fromNode, toNode;
        cin >> fromNode >> toNode;
        fromNode--; toNode--; 
        roadGraph[fromNode].push_back(toNode);
        roadGraph[toNode].push_back(fromNode);
        roadMatrix[fromNode][toNode] = roadMatrix[toNode][fromNode] = 1;
    }

    for (int i = 0; i < totalNodes; i++) {
        for (int j = 0; j < totalNodes; j++) {
            if (roadMatrix[i][j] == 0 && i != j) {
                airGraph[i].push_back(j);
                airGraph[j].push_back(i);
            }
        }
    }

    vector<int> roadDistances(totalNodes, 0), airDistances(totalNodes, 0);
    vector<bool> roadVisited(totalNodes, false), airVisited(totalNodes, false);

    findShortestPaths(roadDistances, roadVisited, roadGraph);
    findShortestPaths(airDistances, airVisited, airGraph);

    if (!roadVisited[totalNodes - 1] || !airVisited[totalNodes - 1]) {
        cout << -1;
    } else {
        cout << max(roadDistances[totalNodes - 1], airDistances[totalNodes - 1]);
    }

    return 0;
}
