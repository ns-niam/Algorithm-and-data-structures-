#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9 + 7;
long long X = 31;

long long getHash(string s)
{
    long long hash = 0;
    long long curX = 1;
    for (long long i = 0; i < s.size(); i++)
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
    for (long long i = 0; i < s.size(); i++)
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

vector<long long> rabinKarp(string s, string t, vector<long long> hashes, long long smallHash)
{
    vector<long long> res;
    for (long long i = 0; i < s.size() - t.size() + 1; i++)
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
            res.push_back(i);
        };
    }
    return res;
}
bool mine_rabinKarp(string s, string t, vector<long long> hashes, long long smallHash)
{
    for (long long i = 0; i < s.size() - t.size() + 1; i++)
    {
        long long hashDif = hashes[i + t.size() - 1];
        if (i != 0)
            hashDif -= hashes[i - 1];
        if (hashDif < 0)
            hashDif += MOD;
        if (i != 0)
            smallHash = (smallHash * X) % MOD;
        if (smallHash == hashDif)
            return true;
    }
    return false;
}
int main()
{
    string s;
    cin >> s;
    long long n;
    cin >> n;
    vector<string> v(n);
    vector<bool> to_check_small(s.size());
    vector<long long> indeces_of_occurences;

    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    bool flag = true;
    vector<long long> hashed_longtape = getPrefixHashes(s);
    for (int i = 0; i < n; i++)
    {
        long long smallHash = getHash(v[i]);
        flag = mine_rabinKarp(s, v[i], hashed_longtape, smallHash);
        indeces_of_occurences = rabinKarp(s, v[i], hashed_longtape, smallHash);
        if (flag == false)
            continue;
        for (int j = 0; j < indeces_of_occurences.size(); j++)
        {
            int index_of_occurence = indeces_of_occurences[j];
            for (int index = 0; index < v[i].size(); index++)
            {
                to_check_small[index_of_occurence + index] = flag; 
            }
        }
    }
    for (long long i = 0; i < to_check_small.size(); i++)
    {
        if (to_check_small[i] == false)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}