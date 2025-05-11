#include <bits/stdc++.h>

using namespace std;

int main(){
    int size_array;
    cin >> size_array;
    
    int array[size_array];
    int sum_of_array = 0;
    
    for(int i = 0; i < size_array; i++){
        cin >> array[i];
        sum_of_array += array[i]; //find sum of array
    }
    cout << sum_of_array << endl;
    return 0;
}