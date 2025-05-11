// Problem E: KH2O - potassium hydroxide???
// One minion is learning chemistry but its going to be so hard. One day when he was doing an experiment with potassium and oxygen, he accidentally blew up the flask. Now this time he wants to be careful with the elements. It has an adjacency matrix where it is written which element can be added with which, and which cannot be added. The teacher gave him 
//  different requests where each request has 
//  chemical elements, it is necessary to say whether it is possible to add these 
//  elements so that the flask does not explode.

// Input format
// The first line contains two integers 
// , 
 
//  — the number of elements and number of queries.

// The next size_of_matrix lines contains 
//  integers 
// , that means element i can be added to element 
//  if 
//  = 
//  and if 
//  = 
//  they cannot be added. It is guaranteed that 

// Output format
// Print “YES” if we can add 
//  elements, otherwise print “NO”.

// Examples
// Input
// 4 4
// 1 1 0 1
// 1 1 1 1
// 0 1 1 0
// 1 1 0 1
// 1 2 4
// 2 3 4
// 1 2 2
// 3 3 4
// Output
// YES
// NO
// YES
// NO


#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> compatibilityMatrix;

vector<vector<int>> read_compatibility_matrix(int elementCount) {
    vector<vector<int>> matrix(elementCount, vector<int>(elementCount));
    for (int row = 0; row < elementCount; row++) for (int col = 0; col < elementCount; col++) cin >> matrix[row][col];
    return matrix;
}

bool can_combine_elements(int elementA, int elementB, int elementC) {
    return compatibilityMatrix[elementA][elementB] == 1 and
           compatibilityMatrix[elementA][elementC] == 1 and
           compatibilityMatrix[elementB][elementC] == 1;
}

void handle_queries(int queryCount) {
    while (queryCount--) {
        int element1, element2, element3;
        cin >> element1 >> element2 >> element3;
        element1--; element2--; element3--;
        if (can_combine_elements(element1, element2, element3)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    int elementCount, queryCount;
    cin >> elementCount >> queryCount;

    compatibilityMatrix = read_compatibility_matrix(elementCount);

    handle_queries(queryCount);

    return 0;
}