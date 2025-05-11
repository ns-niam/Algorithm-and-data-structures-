#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    int revese_num = 0;
    
    while(num != 0){
        revese_num += num % 10; //reverse the number
        revese_num *= 10; //move to the next digit
        num /= 10; //increment the number
    }
    revese_num /= 10; //delete the last 0
    
    cout << revese_num * 2;
    
    return 0;
}