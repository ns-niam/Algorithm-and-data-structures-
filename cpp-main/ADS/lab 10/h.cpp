// Problem H: Number of Island
// Given a map as 2d char array of ‘1’s (land) and ‘0’s (water). Your task to compute the number of islands. An island is set of land cells that are surrounded by water, such that from any cell you can reach any other cell in the islland moving only horizontally or vertically to adjacent cells. You may assume that area outside a map is a water.

// Input format
// In the first line given n and m, size of array (
// ) In the next n line contain m character ‘0’ or ‘1’.

// Output format
// Single number - the number of islands.

// Examples
// Input
// 4 5
// 11110
// 11010
// 11000
// 00000
// Output
// 1


#include <bits/stdc++.h>

using namespace std;

const int MAX_DIM = 100;

char field[MAX_DIM][MAX_DIM]; // Сетка для представления островов
int rowCount, colCount;

// Функция для выполнения DFS и "затопления" текущего острова
void floodFill(int row, int col) {
    if (row < 0 || col < 0 || row >= rowCount || col >= colCount || field[row][col] == '0') {
        return;
    }

    field[row][col] = '0'; // Отмечаем ячейку как посещенную
    floodFill(row, col + 1); // Справа
    floodFill(row, col - 1); // Слева
    floodFill(row + 1, col); // Снизу
    floodFill(row - 1, col); // Сверху
}

int main() {
    int islandCount = 0;
    cin >> rowCount >> colCount;
    for (int row = 0; row < rowCount; row++)
        for (int col = 0; col < colCount; col++)
            cin >> field[row][col];
    for (int row = 0; row < rowCount; row++) for (int col = 0; col < colCount; col++)
            if (field[row][col] == '1') {
                floodFill(row, col); 
                islandCount++;
            }
    cout << islandCount;
    return 0;
}
