#include <bits/stdc++.h>
using namespace std;

int partition(int ar[], int left, int right)
{
    int pivot = ar[right];
    int index = left;
    for (int i = left; i < right; i++)
    {
        if (ar[i] > pivot)
        {
            swap(ar[i], ar[index]);
            index++;
        }
    }
    swap(ar[index], ar[right]);
    return index;
}

void quick_sort(int ar[], int left, int right)
{
    if (left < right)
    {
        int p = partition(ar, left, right);
        quick_sort(ar, left, p - 1);
        quick_sort(ar, p + 1, right);
    }
}

int main()
{
    
    int n, m;
    cin >> n >> m;
    int arr[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[j][i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        quick_sort(arr[i], 0, n - 1);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << arr[j][i] << ' ';
        cout << endl;
    }
    return 0;
}