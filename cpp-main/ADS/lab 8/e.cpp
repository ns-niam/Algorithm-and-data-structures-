#include <iostream>
#include <vector>
using namespace std;

long long MOD = 1e18 + 7;
long long X = 2;

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
string getHash_string(vector<long long> numbers)
{
    string ans = "";
    long long curX = 1;
    for (long long i = 1; i < numbers.size(); i++)
    {
        long long num = numbers[i] - numbers[i - 1];
        long long pastHash = (num / curX + 'a') % MOD;
        ans += pastHash;
        curX = (curX * X) % MOD;
    }
    return ans;
}

// vector<long long> getPrefixHashes(string s)
// {
//     vector<long long> hashes(s.size());
//     long long curX = 1;
//     for (long long i = 0; i < s.size(); i++)
//     {
//         hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
//         if (i != 0)
//         {
//             hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
//         }
//         curX = (curX * X) % MOD;
//     }
//     return hashes;
// }
// long long rabinKarp(string s, string t)
// {
//     long long smallHash = getHash(t);
//     long long res = 0;
//     vector<long long> hashes = getPrefixHashes(s);
//     for (long long i = 0; i < s.size() - t.size() + 1; i++)
//     {
//         long long hashDif = hashes[i + t.size() - 1];
//         if (i != 0)
//             hashDif -= hashes[i - 1];
//         if (hashDif < 0)
//             hashDif += MOD;
//         if (i != 0)
//             smallHash = (smallHash * X) % MOD;
//         if (smallHash == hashDif)
//         {
//             res++;
//         };
//     }
//     return res;
// }

int main()
{
    string s = "";
    string letter = "";
    long long n;
    cin >> n;
    vector<long long> numbers(n + 1, 0);
    for (long long i = 1; i <= n; i++)
    {
        cin >> numbers[i];
    }
    s = getHash_string(numbers);
    cout << s;
    return 0;
}