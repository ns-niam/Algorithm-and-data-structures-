#include <bits/stdc++.h>

using namespace std;

int main (){
    int size , min;
    cin >> size;
    vector<int> vector_array(size);
    
    for(int i = 0; i < size; i++){
        cin >> vector_array[i];
    }
    
    cin >> min;
    
    int check = 0, cnt = 0;

    for(int i = 0; i < vector_array.size(); i++){
        if(vector_array[i] > min){
            for(int j = 2; j <= sqrt(vector_array[i]); j++){
                if(vector_array[i] % j == 0)
                check++;
            }

            if(check == 0){
                cnt++;
            }
        }
        check = 0;
    }
    cout << cnt;
}