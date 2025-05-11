#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    map <string, string> mp;
    for (int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        mp[a] = b;
    }
    int gs;
    cin >> gs;
	while(gs--){
		string login, password;
		cin >> login >> password;
		if(!mp.count(login)) cout << "login error" << endl;
		else if(mp[login] != password) cout << "password error" << endl;
		else cout << "correct password" << endl;	
	}
    return 0;
}