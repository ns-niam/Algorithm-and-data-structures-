#include <bits/stdc++.h>

using namespace std;

int partition(char ar[], int left, int right)
{
    int pivot = ar[right];
    int index = left;
    for (int i = left; i < right; i++)
    {
        if (ar[i] < pivot)
        {
            swap(ar[i], ar[index]);
            index++;
        }
    }
    swap(ar[index], ar[right]);
    return index;
}

void quick_sort(char ar[], int left, int right)
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
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);

    char balanced_char;
    cin >> balanced_char;

    int left = 0;
    int right = n - 1;
    char ans = ' ';
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= balanced_char)
            left = mid + 1;
        else if (arr[mid] <= arr[right]){
            ans = arr[mid];
            right = mid - 1;
        }
    }
    if (ans == ' ')
        ans = arr[0];
    cout << ans;
}