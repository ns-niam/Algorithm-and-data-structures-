#include <iostream>

using namespace std;

int main (){
    string s;
    int a = 0, b = 0;
    cin >> s;
    for (auto i:s){
        if (i >= 'a' && i <= 'z') a++;
        else if (i >= 'A' && i <= 'Z') b++;
    }
    cout << a << " " << b << endl;
    return 0;
}