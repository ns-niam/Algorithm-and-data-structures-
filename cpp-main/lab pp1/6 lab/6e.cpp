#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    float a, b;
    float c;
    cin >> a >> b;
    c = sqrt(a * a + b * b);
    cout << setprecision(4) << c;
}