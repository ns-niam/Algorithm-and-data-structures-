#include <bits/stdc++.h>
using namespace std;

class MergeSort {
    vector<int> vector_to_sort;

public:
    void insert(const vector<int>& first_vector, const vector<int>& second_vector) {
        vector_to_sort.insert(vector_to_sort.end(), first_vector.begin(), first_vector.end());
        vector_to_sort.insert(vector_to_sort.end(), second_vector.begin(), second_vector.end());
    }

    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = vector_to_sort[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = vector_to_sort[mid + 1 + j];

        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                vector_to_sort[k] = L[i];
                i++;
            } else {
                vector_to_sort[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            vector_to_sort[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            vector_to_sort[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }

    void printVector() {
        for (const int& s : vector_to_sort)
            cout << s << " ";
        cout << endl;
    }
};


int main(){
    int size_of_first_vector;
    cin >> size_of_first_vector;
    vector<int> first_vector(size_of_first_vector);
    for(int i = 0; i < size_of_first_vector; i++)
        cin >> first_vector[i];

    int size_of_second_vector;
    cin >> size_of_second_vector;
    vector<int> second_vector(size_of_second_vector);
    for(int i = 0; i < size_of_second_vector; i++)
        cin >> second_vector[i];

    MergeSort Merge;
    Merge.insert(first_vector, second_vector);

    Merge.mergeSort(0, first_vector.size() + second_vector.size() - 1);
    Merge.printVector();

    return 0;
}
