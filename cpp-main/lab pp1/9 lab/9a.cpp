#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	pair <int, int> p[n];
	for(int i = 0; i < n; ++i){
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n);
	for(int i = 0; i < n; ++i){
		cout << p[i].first << " " << p[i].second << endl;
	}
    return 0;
}