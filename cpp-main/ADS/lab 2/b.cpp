#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<string> words(m);    
    for (auto& word : words) cin >> word; 
    rotate(words.begin(), words.begin() + n, words.end());
    for (const auto& word : words) cout << word << " ";
    return 0;
}