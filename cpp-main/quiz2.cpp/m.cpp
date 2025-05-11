#include <bits/stdc++.h>

using namespace std;

int main(){
    int first, second;
    cin >> first >> second;
    int i = 0; //loop power of 2

    if(first > second){
        while(powl(2, i) * second != first){ //check if second is divisible by 2^i
            if(i > 60){ //break out of loop
                cout << "NO" << endl;
                return 0;
            }
            i++;
        }
        cout << "YES -" << i << endl;
    }
    else{
        while(powl(2, i) * first != second){ //check if first is divisible by 2^i
                if(i > 60){ //break out of loop
                    cout << "NO" << endl;
                    return 0;
                }
                i++;
            }
            cout << "YES " << i << endl;
    }
    return 0;   
}