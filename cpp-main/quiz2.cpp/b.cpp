#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y;
    int n;
    cin >> x >> y >> n;
    int arr[x][y];

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++) 
            arr[i][j] = 0; //giving 0 to all elements in 2-D array

    for (int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
            for ( ; x1 < x2; x1++)
                for (int j = y1; j < y2; j++)
                    arr[x1][j]++; //painting the square
    } 

    //to know what's going on
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    int cnt = 0;
    for (int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            if(arr[i][j] == 0) cnt++; //count the number of 0s
        
    

    cout << cnt << endl;
    return 0;
}