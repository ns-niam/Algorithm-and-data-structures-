#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> b, n;
    int cnt = 0;
    for (int i = 0; i < 5; i++){
        int n;
        cin >> n;
        b.push_back(n);
    }
    for (int i = 0; i < 5; i++){
        int n;
        cin >> n;
        n.push_back(n);
    }
    int num2;
    int num1;
    while ((!b.empty() && !n.empty())){
        num1 = b.front();
        num2 = n.front();
        if (num1 > num2){
            if ((num1 == 9 && num2 == 0)){
                n.push_back(num1);
                n.push_back(num2);
                b.pop_front();
                n.pop_front();
            }else{
                b.push_back(num1);
                b.push_back(num2);
                b.pop_front();
                n.pop_front();
            }
        }
        if (num1 < num2){
            if ((num1 == 0 && num2 == 9)){
                b.push_back(num1);
                b.push_back(num2);
                b.pop_front();
                n.pop_front();
            }else{
                n.push_back(num1);
                n.push_back(num2);
                b.pop_front();
                n.pop_front();
            }
        }
        cnt++;
        if (cnt == 1000000){
            cout << "blin nichya" << endl;
            return 0;
        }
    }
    if (b.empty()) cout << "n " << cnt << endl;
    else cout << "b " << cnt << endl;
    return 0;
}