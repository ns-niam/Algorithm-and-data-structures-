#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string s)
{
    vector<int> pi(s.size());
    pi[0] = 0;
    for (int i = 1; i < s.size(); i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
        {
            j = pi[j - 1];
        }
        if (s[j] == s[i])
        {
            pi[i] = j + 1;
        }
        else
        {
            pi[i] = 0;
        }
    }

    return pi;
}

int main()
{
    string s;
    cin >> s;
    vector<int> pi = prefixFunction(s);
    int l = pi[s.size()-1];
    cout << s.size()-l;
    return 0;
}