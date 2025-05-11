#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int first_row [n], second_row [n]; 
    int cnt = 0;
    for(int i = 0; i < n; i++)
        cin >> first_row[i];
    
    for(int i = 0; i < n; i++)
        cin >> second_row[i];
    
    int time;
    cin >> time;
    
    for(int i = 0; i < n; i++){
        
        if(time <= second_row[i] && first_row[i] <= time) cnt++; //count the number of people that can attend
    }
    cout << cnt << endl;
    return 0;
}