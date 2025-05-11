#include <bits/stdc++.h>

using namespace std;

int joke (string a){
    int sum = 0;
    for (auto s : a){
        if (s=='1') sum++;
        else if (s=='0') sum+=0;
        else if (s=='3') sum+=3;
        else if (s=='2') sum+=2;
        else if (s=='5') sum+=5;
        else if (s=='4') sum+=4;
        else if (s=='7') sum+=7;
        else if (s=='6') sum+=6;
        else if (s=='9') sum+=9;
        else if (s=='8') sum+=8;
    }
    return sum;
}
int main (){
    string a;
    getline (cin, a);
    cout << joke(a);
    return 0;
}