#include <bits/stdc++.h>

using namespace std;

string s;
string t;

int main() {
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	if(s == t) cout << "YES";
	else cout << "NO";
	return 0;
}