#include <bits/stdc++.h>
using namespace std;

string vowels = "aeiou";

bool comp(char a, char b){
    if (vowels.find(a) != string::npos && vowels.find(b) != string::npos)
        return a < b;
    else if (vowels.find(a) != string::npos && vowels.find(b) == string::npos)
        return true;
    else if (vowels.find(b) != string::npos && vowels.find(a) == string::npos)
        return false;
    else
        return a < b;
}

int partition(char ar[], int left, int right){
    char pivot = ar[right];
    int index = left;
    for (int i = left; i < right; i++)
        if (comp(ar[i], pivot)){
            swap(ar[i], ar[index]);
            index++;
        }
    swap(ar[index], ar[right]);
    return index;
}

void quick_sort(char ar[], int left, int right){
    if (left < right){
        int p = partition(ar, left, right);
        quick_sort(ar, left, p - 1);
        quick_sort(ar, p + 1, right);
    }
}

int main(){
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i];
    return 0;
}