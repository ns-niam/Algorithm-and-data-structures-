#include <bits/stdc++.h>

using namespace std;

vector<int> findCommonElementsWithMultiplicity(const vector<int>& vec1, const vector<int>& vec2) {
    unordered_map<int, int> elementCount;
    vector<int> commonElements;

    for (int num : vec1)
        elementCount[num]++;

    for (int num : vec2)
        if (elementCount[num] > 0) {
            commonElements.push_back(num);
            elementCount[num]--; 
        }
    return commonElements;
}



int main(){
    int first_size, second_size;
    cin >> first_size >> second_size;
    vector<int> first_vector(first_size);
    vector<int> second_vector(second_size);
    for(int i = 0; i < first_size; i++)
        cin >> first_vector[i];
    for(int i = 0; i < second_size; i++)
        cin >> second_vector[i];
    vector<int> result = findCommonElementsWithMultiplicity(first_vector, second_vector);
    sort(result.begin(), result.end());
    for(int i : result) 
        cout << i << " ";
    return 0;
} 