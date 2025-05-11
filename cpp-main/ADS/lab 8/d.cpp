#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
long long X = 31;

long long getHash(string s)
{
    long long hash = 0;
    long long curX = 1;
    for (int i = 0; i < s.size(); i++)
    {
        long long curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

vector<long long> getPrefixHashes(string s)
{
    vector<long long> hashes(s.size());
    long long curX = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0)
        {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}
int rabinKarp(string s, string t)
{
    long long smallHash = getHash(t);
    int res = 0;
    vector<long long> hashes = getPrefixHashes(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++)
    {
        long long hashDif = hashes[i + t.size() - 1];
        if (i != 0)
            hashDif -= hashes[i - 1];
        if (hashDif < 0)
            hashDif += MOD;
        if (i != 0)
            smallHash = (smallHash * X) % MOD;
        if (smallHash == hashDif)
        {
            res++;
        };
    }
    return res;
}

int main()
{
    int n;
    long long max = 0;
    vector<pair<string, int>> dominating_patterns;
    vector<string> input_cyphers;
    string cyphers;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> cyphers;
            input_cyphers.push_back(cyphers);
        }
        string text;
        cin >> text;
        for (int i = 0; i < input_cyphers.size(); i++)
        {
            int freq = rabinKarp(text, input_cyphers[i]);
            if (freq > max)
                max = freq;
            dominating_patterns.push_back({input_cyphers[i],freq});
        }
        cout << max << endl;
        for (auto i : dominating_patterns)
        {
            if (i.second == max)
            {
                cout << i.first << endl;
            }
        }
        dominating_patterns.clear();
        input_cyphers.clear();
        max = 0;
    }
}