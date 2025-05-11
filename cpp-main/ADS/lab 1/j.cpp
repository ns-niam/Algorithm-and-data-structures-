#include <bits/stdc++.h>

using namespace std;

int main(){
    char c;
    int num;
    cin >> c;
    deque<int> dq;
    while(c != '!'){
        if(c == '*'){
            if(dq.size()>=1){
                int ans = dq.front()+dq.back();
                cout << ans << endl;
                if(dq.size()==1){
                    dq.pop_back();
                }else{
                    dq.pop_back();dq.pop_front();
                }
            }
            else if(dq.empty()){
                cout<< "error" << endl;;
            }

        } else {
            cin >> num;
            if(c == '+') dq.push_front(num);
            else if(c == '-') dq.push_back(num);
        }
        cin >> c;
    }
}