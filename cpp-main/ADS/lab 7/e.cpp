#include <bits/stdc++.h>

using namespace std;

class MergeSort {
private:
    vector<vector<int>> data;

public:
    void insert(const vector<vector<int>>& input_data) {
        data = input_data;
    }

    void mergeSort(int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }

    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<vector<int>> leftData(n1), rightData(n2);

        for (int i = 0; i < n1; i++)
            leftData[i] = data[left + i];
        for (int j = 0; j < n2; j++)
            rightData[j] = data[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            int sumLeft = accumulate(leftData[i].begin(), leftData[i].end(), 0);
            int sumRight = accumulate(rightData[j].begin(), rightData[j].end(), 0);

            if (sumLeft > sumRight) {
                data[k] = leftData[i];
                i++;
            } else if (sumLeft < sumRight) {
                data[k] = rightData[j];
                j++;
            } else {
                if (leftData[i] < rightData[j]) {
                    data[k] = leftData[i];
                    i++;
                } else {
                    data[k] = rightData[j];
                    j++;
                }
            }
            k++;
        }

        while (i < n1) {
            data[k] = leftData[i];
            i++;
            k++;
        }

        while (j < n2) {
            data[k] = rightData[j];
            j++;
            k++;
        }
    }


    void printResults() {
        for (const auto& vec : data) {
            for (int num : vec)
                cout << num << " ";
            cout << endl;
        }
    }
};

int main() {
    int size_of_rows, size_of_columns;
    cin >> size_of_rows >> size_of_columns; 

    MergeSort mergeSort;

    vector<vector<int>> input_data(size_of_rows, vector<int>(size_of_columns));

    for (int i = 0; i < size_of_rows; i++)
        for (int j = 0; j < size_of_columns; j++)
            cin >> input_data[i][j];  
    mergeSort.insert(input_data);
    mergeSort.mergeSort(0, size_of_rows - 1); 
    mergeSort.printResults();  
    return 0;
}
