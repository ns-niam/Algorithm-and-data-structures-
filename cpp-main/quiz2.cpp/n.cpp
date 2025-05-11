#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string symm, check_symm;

    for(int i = 0; i < n; i++){
        int d;
        cin >> d;

        if (d % 10 == 0) //check for zeros
            while(d % 10 == 0) 
                d /= 10; //erase zeros
        
        symm += to_string(d) + ' '; //convert to string
    }
    symm.erase(symm.size() - 1); //remove last space
    check_symm = symm; //check for symmetry
    
    reverse(check_symm.begin(), check_symm.end()); //reverse string
    
    //if (check_symm[0] == ' ') check_symm.erase(0, 1); //erase leading space
    //if (symm.back() == ' ') symm.erase(symm.end() - 1, symm.end()); //erase trailing space
    
    //cout << check_symm << "\n" << symm << "\n"; //check for symmetry and print
    
    if (symm == check_symm) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
