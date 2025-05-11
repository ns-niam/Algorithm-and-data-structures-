// Problem F: John's graph
// Mom gave John an undirected graph for his birthday. After some time, he came up with a game with a graph. He takes two vertices and checks to see if they are in the same component.

// Input format
// The first line contains two integers n and m (2 
//  n 
//  100000, 0 
//  m 
//  99999), where n is the number of vertices and m is the number of edges. Following m lines contain one edge each in form x, y (1 
//  x, y 
//  n), where x, y are edge endpoints. The last line contains two integers s and f (1 
//  s, f 
//  n), vertices you have to check.

// Output format
// Print "YES", if s and f vertices are in the same component, otherwise print "NO".

// Examples
// Input
// 3 3
// 1 2
// 2 3
// 3 1

// 1 3
// Output
// YES
// Input
// 4 2
// 1 2
// 2 3

// 1 4
// Output
// NO


#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> matrix;
vector<int> color;

void dfs_func(int change){
    color[change] = 1;
    for(int i : matrix[change]){
        if(color[i] == 0)
            dfs_func(i);
    }
}

int main(){
    int num_of_vertices, num_of_edges;
    cin >> num_of_vertices >> num_of_edges;
    matrix = vector<vector<int>>(num_of_vertices);
    color = vector<int>(num_of_vertices);
    for(int i = 0; i < num_of_edges; i++){
        int start_pnt, end_pnt;
        cin >> start_pnt >> end_pnt;
        start_pnt--; end_pnt--;
        matrix[start_pnt].push_back(end_pnt);
        matrix[end_pnt].push_back(start_pnt);
    }
    int s_vertic, f_vertic;
    cin >> s_vertic >> f_vertic;
    s_vertic--; f_vertic--;
    bool chck = false;
    dfs_func(s_vertic);

    for(int i = 0; i < num_of_vertices; i++) if(color[i] == 1 and i == f_vertic) chck = true;
    if(chck) cout << "YES";
    else cout << "NO";
    return 0;
}