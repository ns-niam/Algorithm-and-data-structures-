#include <bits/stdc++.h>

using namespace std; 

int main(){ 
    int w, h; 
    cin >> w >> h;

    int all_digits[w * h]; //double array

    for(int i = 0; i < w * h; i++) 
        cin >> all_digits[i]; 
    
    sort(all_digits, all_digits + w * h); //sort the array(first number of the array is minimum number and last number is maximum number)
    
    int front = 0, back = w * h - 1; //front is the index of the maximum number and back is the index of the minimum number
    
    int rmd = front, rmd1 = back;

    for(int i = 0; i < w; i++){
        
        for(int j = 0; j < h; j++){
            if (rmd1 == back) {
                cout << all_digits[back--] << " ";
                rmd = front;
            }
            else {
                cout << all_digits[front++] << " ";
                rmd1 = back;
            }
        }
        cout << endl;
    }
    return 0;     
}