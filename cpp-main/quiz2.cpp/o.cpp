#include <bits/stdc++.h>

using namespace std;

int main(){
    int subjects, grades;
    cin >> subjects >> grades;
    
    int array[subjects][grades];
    int sum_grades[subjects] = {0};

    for(int i = 0; i < subjects; i++){
        for(int j = 0; j < grades; j++){
            cin >> array[i][j];
            sum_grades[i] += array[i][j]; //sum of grades
        }
    }

    for(int i = 0; i < subjects; i++){
        cout << sum_grades[i] / grades << " "; //average of grades
    }
    return 0;
}