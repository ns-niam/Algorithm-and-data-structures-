#include <bits/stdc++.h>

using namespace std;

string polindrom (string arr){
    int a [2], cnt = 0;
    for (int i = 0; i < arr.length(); i++){
        if ((int)arr[i] + 1 == (int) arr[arr.length() - 1 - i] || (int) arr[i] - 1 == (int) arr[arr.length() - 1 - i]){
            cnt++;
        }
    }
    if (cnt == arr.length()) return "YES";
    else return "NO";
    //for (int i = 0; i < arr.length(); i++){
    //    a[arr[i] - '(']++;    
    //}
    //if (a[0] % 2 == 0 && a[1] % 2 == 0){
    //    return "YES";
    //}
    //else {
    //    return "NO";
    //}
}

int main (){
    string s;
    cin >> s;
    cout << polindrom(s);
    return 0;
}