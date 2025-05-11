#include <bits/stdc++.h>

using namespace std;

int main(){
    int size_of_array, find_sum; cin >> size_of_array >> find_sum;
    vector<int> array_of_finding(size_of_array);
    for(int i = 0; i < size_of_array; i++) 
        cin >> array_of_finding[i];
    int left_index = 0, current_sum = 0, min_length = INT_MAX;
    for (int right_index = 0; right_index < size_of_array; right_index++) {
        current_sum += array_of_finding[right_index];
        while (current_sum >= find_sum) {
            min_length = min(min_length, right_index - left_index + 1);
            current_sum -= array_of_finding[left_index];
            left_index++;
        }
    }
    cout << min_length << endl;
    return 0;
}