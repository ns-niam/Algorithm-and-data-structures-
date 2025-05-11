// Problem I: Beta Tester
// Arman works as a beta tester for a game development company. Today he is testing a game that has quests, and in order to win the game, the player needs to complete all the quests. However, some quests only become available after completing certain other quests. The developers give Arman a list of requirements, which indicates which quest must be completed in order to open the next one. Help Arman determine whether is it possible to complete this game, and if possible, output one of the scenarios for the passage.

// Input format
// The first line of input contains a pair of numbers n and m (
// ), the number of quests and requirements, respectively. The next m lines contains a pair of integers i and j (
// ), which means that in order to make quest j available, you must complete quest i.

// Output format
// Determine whether it is possible to complete the game, and output ‘Impossible’ if not, otherwise output ‘Possible’ and the scenario of the passage. If there are several of them, output any.

// Examples
// Input
// 5 5
// 1 2
// 2 3
// 1 3
// 4 5
// 3 4
// Output
// Possible
// 1 2 3 4 5 


#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1e5 + 1;

vector<int> graph[MAX_NODES], topoSort;
int nodeStatus[MAX_NODES]; // 0 - не посещен, 1 - в процессе, 2 - завершен

// Рекурсивная функция для поиска топологического порядка
void performDFS(int node) {
    if (nodeStatus[node] == 1) { 
        cout << "Impossible" << endl;
        exit(0);
    }

    if (nodeStatus[node] == 2) return;

    nodeStatus[node] = 1; 

    for (int neighbor : graph[node]) performDFS(neighbor);

    nodeStatus[node] = 2; // Завершили обработку узла
    topoSort.push_back(node); // Добавляем в топологический порядок
}

int main() {
    int nodeCount, edgeCount;
    cin >> nodeCount >> edgeCount;

    for (int i = 0; i < edgeCount; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    for (int node = 1; node <= nodeCount; node++)
        if (nodeStatus[node] == 0)
            performDFS(node);

    cout << "Possible" << endl;

    reverse(topoSort.begin(), topoSort.end());
    for (int node : topoSort)
        cout << node << " ";

    return 0;
}