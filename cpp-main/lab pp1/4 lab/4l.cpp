#include <iostream>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int a[n][m];
    int min;
    int xIndex = 1, yIndex = 1, summ = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
        cin >> a[i][j];
        }
    }
    
    cout << "coordinates of min elements:" << endl;
    
    for (int i = 0; i < m; i++){
        min = a[0][i];
        yIndex = i + 1;
        for (int j = 0; j < n; j++){
            if (min > a[j][i]){
                min = a[j][i];
                xIndex = j + 1;
            } 
        }
        summ += min;
        cout << xIndex << ";" << yIndex << endl;
    }

    cout << endl << "Their sum:" << endl << summ;

    return 0;
}