// Problem J: Who has a big Family?
// Given a graph without cycles or self loops. In any connected component of the graph, vertex with the lowest value in that component serves as the root. A vertex is BigFam if it is a root or it has more children than its parent. Count the number of BigFam vertices in the given graph.

// Input format
// On the first line there are two separated integers 
//  and 
//  (
// ) and the following 
//  lines consist of two separated integers 
//  and 
//  meaning that there is an edge between vertices X and Y.

// Output format
// Print the number of BigFam vertices.

// Examples
// Input
// 4 3
// 1 2
// 2 3
// 2 4
// Output
// 2

#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    int vertexCount;                         // Количество вершин
    vector<vector<int>> adjacencyList;       // Список смежности
    vector<int> parents;                     // Родитель для каждой вершины

public:
    // Конструктор
    Graph(int n) : vertexCount(n), adjacencyList(n), parents(n, -1) {}

    // Добавление ребра в граф
    void addEdge(int from, int to) {
        from--; to--; // Преобразуем к 0-индексации
        adjacencyList[from].push_back(to);
        parents[to] = from; // Устанавливаем родителя
    }

    // Подсчет количества BigFam вершин
    int countBigFamVertices() const {
        int count = 0;
        for (int i = 0; i < vertexCount; i++) {
            // Условие для BigFam:
            // 1. Вершина является корнем (нет родителя).
            // 2. У вершины больше детей, чем у её родителя.
            if (parents[i] == -1 || adjacencyList[parents[i]].size() < adjacencyList[i].size()) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    // Создаем граф с n вершинами
    Graph graph(n);

    // Считываем m ребер
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph.addEdge(from, to);
    }

    // Выводим количество BigFam вершин
    cout << graph.countBigFamVertices() << endl;

    return 0;
}
