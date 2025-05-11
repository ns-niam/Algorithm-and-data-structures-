#include <bits/stdc++.h>

using namespace std;

const int INFINITY_COST = numeric_limits<int>::max();

class Graph {
private:
    int vertexCount;                             // Количество вершин
    vector<vector<int>> adjacencyMatrix;         // Матрица смежности

public:
    Graph(int vertices) : vertexCount(vertices), adjacencyMatrix(vertices, vector<int>(vertices, INFINITY_COST)) {}

    // Метод для добавления рёбер в матрицу смежности
    void addEdge(int fromVertex, int toVertex, int weight) {
        adjacencyMatrix[fromVertex][toVertex] = weight;
        adjacencyMatrix[toVertex][fromVertex] = weight;
    }

    // Алгоритм Прима для нахождения минимального остовного дерева (MST)
    int findMinimumSpanningTree() {
        vector<bool> isVertexInMST(vertexCount, false);  // Отслеживает, включена ли вершина в MST
        vector<int> minimumEdgeCost(vertexCount, INFINITY_COST);  // Минимальная стоимость рёбер для каждой вершины
        vector<int> mstParent(vertexCount, -1);          // Родительская вершина в MST

        minimumEdgeCost[0] = 0; // Начинаем с первой вершины
        int totalWeight = 0;

        for (int step = 0; step < vertexCount; ++step) {
            int selectedVertex = -1;

            // Находим вершину с минимальным значением в `minimumEdgeCost`
            for (int vertex = 0; vertex < vertexCount; ++vertex) {
                if (!isVertexInMST[vertex] && 
                    (selectedVertex == -1 || minimumEdgeCost[vertex] < minimumEdgeCost[selectedVertex])) {
                    selectedVertex = vertex;
                }
            }

            isVertexInMST[selectedVertex] = true; // Помечаем вершину как включённую в MST

            // Добавляем вес ребра в общий вес MST
            if (mstParent[selectedVertex] != -1) {
                totalWeight += adjacencyMatrix[selectedVertex][mstParent[selectedVertex]];
            }

            // Обновляем минимальные стоимости рёбер для соседей
            for (int neighbor = 0; neighbor < vertexCount; ++neighbor) {
                if (!isVertexInMST[neighbor] && adjacencyMatrix[selectedVertex][neighbor] < minimumEdgeCost[neighbor]) {
                    minimumEdgeCost[neighbor] = adjacencyMatrix[selectedVertex][neighbor];
                    mstParent[neighbor] = selectedVertex;
                }
            }
        }

        return totalWeight;
    }
};

int main() {
    int n;
    cin >> n;

    Graph graph(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight;
            cin >> weight;
            if (weight != 0) { 
                graph.addEdge(i, j, weight);
            }
        }
    }

    int totalWeight = graph.findMinimumSpanningTree();
    cout << totalWeight << endl;

    return 0;
}
