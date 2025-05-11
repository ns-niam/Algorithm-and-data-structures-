#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    int soccer [x][y];

    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            cin >> soccer[i][j];

    int limit;
    cin >> limit;

    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            if(limit + 1 <= soccer[i][j]){ //if the limit is greater than the soccer field, print penalty
                cout << "Penalty!" << endl;
                return 0;
            }        
    cout << "No penalty for today." << endl; //no penalty for today
    return 0;
}