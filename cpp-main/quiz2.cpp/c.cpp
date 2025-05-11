#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    string odd_digit, even_digit;
    
    for(int i = 0; i < n; i++){
        
        cin >> arr[i];

        if(arr[i] % 2 == 0){
            even_digit += to_string(arr[i]) + " "; //Giving the even digits
        }

        else if(arr[i] % 2 == 1){
            odd_digit += to_string(arr[i]) + " "; //Giving the odd digits
        }
    }

    cout << even_digit << odd_digit << endl;
    return 0;
}