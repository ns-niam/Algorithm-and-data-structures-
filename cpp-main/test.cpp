#include <bits/stdc++.h>

using namespace std;


int main() {
    set<int> data ;
    data.insert(10);
    data.insert(10);
    data.insert(20);
    data.insert(20);
    data.insert(30);
    data.insert(30);
    data.insert(40);
    data.insert(40);
    int sum = 0;
    set<int, greater<int> >::iterator itr;

    for ( itr = data.begin(); itr != data.end(); itr++ )
    {
        sum+=*itr;
    }
    
    cout<<"the sum ="<<sum <<endl;
    return 0;
}