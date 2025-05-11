#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int size_queue;
    deque<int> dq;
    for (int i = 0; i < n; i++){
        cin >> size_queue;
        for (int j = size_queue; j > 0; j--){
            dq.push_back(j);

            for (int k = 0; k <= j; k++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        while (!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
    }
}