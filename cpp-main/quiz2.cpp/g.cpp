#include <bits/stdc++.h>

using namespace std;

int main(){
    int first, second, side;
    cin >> first >> second >> side;

    int f_sqrt = sqrt(first); //square root of first
    int s_sqrt = sqrt(second); //square root of second
    
    if(side == 1) //from first to second
        while(f_sqrt <= s_sqrt){
            cout << powl(f_sqrt,2) << " "; //power of first square root
            f_sqrt++;
        }

    else //from second to first
        while(f_sqrt <= s_sqrt){
            cout << powl(s_sqrt,2) << " "; //power of second square root
            s_sqrt++;
        }
    return 0;
}