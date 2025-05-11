#include <bits/stdc++.h>
using namespace std;

bool binsearch(int nums[], int size, int target){
    int low = 0, high = size - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return true;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target;
    if (binsearch(arr, n, target))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}