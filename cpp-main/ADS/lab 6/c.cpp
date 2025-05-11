#include <bits/stdc++.h>
using namespace std;

void findMinDiff(int arr[], int size){
    vector<vector<int>> result;
    int min_diff = INT_MAX;

    // find min difference
    for (int i = 0; i < size - 1; ++i)
        min_diff = min(arr[i + 1] - arr[i], min_diff);
    // form a list of pairs with min difference, ascending
    for (int i = 0; i < size - 1; ++i)
        if (arr[i + 1] - arr[i] == min_diff)
            result.push_back({arr[i], arr[i + 1]});
    for (int i = 0; i < result.size(); i++)
        for (int j = 0; j < result[0].size(); j++)
            cout << result[i][j] << ' ';
}

int partition(int ar[], int left, int right){
    int pivot = ar[right];
    int index = left;
    for (int i = left; i < right; i++)
        if (ar[i] < pivot){
            swap(ar[i], ar[index]);
            index++;
        }
    swap(ar[index], ar[right]);
    return index;
}

void quick_sort(int ar[], int left, int right){
    if (left < right){
        int p = partition(ar, left, right);
        quick_sort(ar, left, p - 1);
        quick_sort(ar, p + 1, right);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quick_sort(arr, 0, n - 1);

    findMinDiff(arr, n);
    return 0;
}