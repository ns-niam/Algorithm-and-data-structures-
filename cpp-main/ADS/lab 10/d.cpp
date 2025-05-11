// Submit a solution for D-Try Again
// Time limit:	5 s
// Real time limit:	10 s
// Memory limit:	256M
// Problem D: Try Again
// You are given undirected graph with 
//  vertices, 
//  edges, and 
//  queries. Initially all vertices are black. There are two types of queries.

// 1.  
//  - Change the color of vertex 
//  to red.

// 2.  
//  - Output the distance to the nearest red vertex to 
// , or -1 is there is no such vertex.

// Input format
// First line contains three integers 
// . Next 
//  lines contain information about edges. Next 
//  lines contain queries as described in the statement.

// Output format
// Output answer to queries of type 
// .

// Examples
// Input
// 5 4 7
// 1 2
// 2 3
// 3 4
// 4 5
// 2 1
// 1 1
// 2 1
// 2 2
// 2 5
// 1 3
// 2 5
// Output
// -1
// 0
// 1
// 4
// 2


#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 5009;
const int UNVISITED = 0, VISITED = 1;
int distanceFromSource[MAX_NODES], nodeColor[MAX_NODES];
vector<int> adjacencyList[MAX_NODES];
bool isNodeProcessed[MAX_NODES];

void initialize_distances(int totalNodes) {
    for (int i = 1; i <= totalNodes; i++) {
        distanceFromSource[i] = INT_MAX;
    }
}

void add_edge(int startNode, int endNode) {
    adjacencyList[startNode].push_back(endNode);
    adjacencyList[endNode].push_back(startNode);
}

void perform_bfs(int startNode) {
    queue<int> nodeQueue;
    nodeQueue.push(startNode);
    isNodeProcessed[startNode] = true;
    distanceFromSource[startNode] = 0;

    while (!nodeQueue.empty()) {
        int currentNode = nodeQueue.front();
        nodeQueue.pop();

        for (int i = 0; i < adjacencyList[currentNode].size(); i++) {
            int adjacentNode = adjacencyList[currentNode][i];
            if (distanceFromSource[adjacentNode] > distanceFromSource[currentNode] + 1) {
                distanceFromSource[adjacentNode] = distanceFromSource[currentNode] + 1;
                isNodeProcessed[adjacentNode] = true;
                nodeQueue.push(adjacentNode);
            }
        }
    }
}

void handle_query(int queryType, int node) {
    if (queryType == 1) {
        if (nodeColor[node] != VISITED) {
            perform_bfs(node);
            nodeColor[node] = VISITED;
        }
    } else {
        if (distanceFromSource[node] == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << distanceFromSource[node] << endl;
        }
    }
}

int main() {
    int totalNodes, totalEdges, totalQueries;
    cin >> totalNodes >> totalEdges >> totalQueries;

    for (int i = 1; i <= totalEdges; i++) {
        int startNode, endNode;
        cin >> startNode >> endNode;
        add_edge(startNode, endNode);
    }

    initialize_distances(totalNodes);

    while (totalQueries--) {
        int queryType, node;
        cin >> queryType >> node;
        handle_query(queryType, node);
    }

    return 0;
}