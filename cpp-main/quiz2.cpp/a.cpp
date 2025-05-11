#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, sum_even = 0, sum_odd = 0, cnt_even = 0, cnt_odd = 0;
    
    cin >> n;
    
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];

        if(arr[i] % 2 == 0) {
            sum_even += arr[i]; //summary of even numbers
            cnt_even++; //count of even numbers
        }
        else if (arr[i] % 2 == 1) {
            sum_odd += arr[i]; //summary of odd numbers
            cnt_odd++; //count of odd numbers
        }
    }
    
    cout << "Left hand magic power: " << sum_even * cnt_even << "\n";
    cout << "Right hand magic power: " << sum_odd * cnt_odd << "\n";
    return 0;
}