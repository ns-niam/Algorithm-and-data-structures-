#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_VERTICES = 200005;

int dsuParent[MAX_VERTICES], dsuRank[MAX_VERTICES]; 
vector<int> adjacencyList[MAX_VERTICES];           
vector<int> connectedComponents;

void initializeDSU() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        dsuParent[i] = i;
        dsuRank[i] = 1;
    }
}

int findRoot(int vertex) {
    return (dsuParent[vertex] == vertex) ? vertex : (dsuParent[vertex] = findRoot(dsuParent[vertex]));
}

bool uniteSets(int vertexA, int vertexB) {
    int rootA = findRoot(vertexA);
    int rootB = findRoot(vertexB);

    if (rootA == rootB)
        return false; 

    if (dsuRank[rootA] < dsuRank[rootB]) {
        dsuParent[rootA] = rootB;
    } else if (dsuRank[rootB] < dsuRank[rootA]) {
        dsuParent[rootB] = rootA;
    } else {
        dsuParent[rootA] = rootB;
        dsuRank[rootB]++;
    }

    return true;
}

int main() {
    int vertexCount, edgeCount;
    int componentCount = 0; 

    initializeDSU();

    cin >> vertexCount >> edgeCount;
    for (int i = 0; i < edgeCount; i++) {
        int vertexU, vertexV;
        cin >> vertexU >> vertexV;
        adjacencyList[vertexU].push_back(vertexV);
        adjacencyList[vertexV].push_back(vertexU);
    }

    for (int currentVertex = vertexCount; currentVertex >= 1; currentVertex--) {
        componentCount++; 
        for (int neighbor : adjacencyList[currentVertex]) {
            if (currentVertex < neighbor && findRoot(currentVertex) != findRoot(neighbor)) {
                componentCount--;
                uniteSets(currentVertex, neighbor);
            }
        }
        connectedComponents.push_back(componentCount);
    }
    reverse(connectedComponents.begin(), connectedComponents.end());
    for (int i = 1; i < connectedComponents.size(); i++) {
        cout << connectedComponents[i] << endl;
    }

    cout << 0 << endl;

    return 0;
}
