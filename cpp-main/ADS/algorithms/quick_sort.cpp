#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
  

    // Выберите поворотную точку
    int pivot = arr[high];
  
 
    // Индекс меньшего элемента и указывает 
    // правое положение шарнира, найденное на данный момент

    int i = low - 1;

    // Пересекаем arr[;ow..high] и перемещаем все меньшие
    // элементы на левую сторону. Элементы от low до 
    // i становятся меньше после каждой итерации

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
 
    // Переместите шарнир после меньших элементов и
    // вернуть его положение

    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);
        for(int i : arr) cout << i << " ";
        cout << endl;
        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
  
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}