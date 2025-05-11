#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int arr2[], int n, int m){
    int i = 0, j = 0;
    while (i < n && j < m){
        if (arr[i] > arr2[j])
            j++;
        else if (arr2[j] > arr[i])
            i++;
        else{
            cout << arr[i] << " ";
            i++;
            j++;
        }
    }
}

int partition(int ar[], int left, int right){
    int pivot = ar[right];
    int index = left;
    for (int i = left; i < right; i++){
        if (ar[i] < pivot){
            swap(ar[i], ar[index]);
            index++;
        }
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
    int n, m;
    cin >> n >> m;
    int arr[n], arr2[m];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    quick_sort(arr, 0, n - 1);
    quick_sort(arr2, 0, m - 1);
    merge(arr, arr2,n,m);
    return 0;
}