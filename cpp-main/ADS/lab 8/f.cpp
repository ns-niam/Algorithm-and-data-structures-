#include <bits/stdc++.h>
using namespace std;

long long MOD = 9007199254740881;
long long X = 31;

long long getHash(char s)
{
    long long hash = 0;
    long long curX = 1;

    long long curHash = (s - 'a' + 1) * curX % MOD;
    hash = (hash + curHash) % MOD;
    curX = (curX * X) % MOD;

    return hash;
}
// vector<long long> getPrefixHashes(string s)
// {
//     vector<long long> hashes(s.size());
//     long long curX = 1;
//     for (int i = 0; i < s.size(); i++)
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

// vector<int> rabinKarp(string s, string t)
// {
//     long long smallHash = getHash(t);
//     vector<int> res;
//     vector<long long> hashes = getPrefixHashes(s);
//     for (int i = 0; i < s.size() - t.size() + 1; i++)
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
//             res.push_back(i);
//         };
//     }
//     return res;
// }
int main()
{
    // AUTHOR: Amanbek Faizolla
    string s;
    cin >> s;
    long long cnt = 0;
    unordered_map<unsigned long long, unsigned long long> mp;
    for (int i = 0; i < s.size(); i++)
    {
        long long hash = 0;
        for (int j = i; j < s.size(); j++)
        {
            hash = (hash * 26 + s[j]) % MOD;//rolling hash
            if (mp.find(hash) == mp.end())
            {
                cnt++;
            }
            mp[hash] = 1;
        }
    }
    cout << cnt;

    // SOLUTION ABOVE WITH HASHING

    // unordered_set<string> st;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     string ss = "";
    //     for (int j = i; j < s.size(); j++)
    //     {
    //         ss += s[j];
    //         st.insert(ss);
    //     }
    // }
    // cout << st.size();
    /*
                          ......
                   .:!?Y5PPPGGPPP5Y?!:.
                .!YPGGP55YYJJJJYY55PGGPY!.
              ^JGBPYJJJJJJJY5PP5YJJJJJYPBGJ^
            :YBG5JJJJJJJJJPBBBBPYJJJJJJJJ5GBY:
           7BB5JJJJJJJJYY5BBBBBB5YYJJJJJJJJ5BB7
          J#GJJJJJJJY555YY5GBBG5YY555YJJJJJJJG#J
         ?#GJJJJJJY5PYJJJJJJJJJJJJJJYP5YJJJJJJG#?
        ^BBJJJJJJYP5JJJJJJJJJJJJJJJJJJ5PYJJJJJJBB^
        J#PJJJJJJ55JJJJJJYPGBBGPYJJJJJJ55JJJJJJP#J
        5#YJJJJJYP5JJJJJJBBBBBBBBJJJJJJ5PYJJJJJY#5
        5#YJJJJJYP5JJJJJJBBBBBBBBJJJJJJ5PYJJJJJY#5
        J#PJJYGYPBBGPYJJJYPGBBGPYJJJCYPGBBPYJJJJP#J
        ^BBJJJGBBBBB#PJJJJJJJJJJJJJJP#BBBBGJJJJBB^
         ?#GJJJPGBBBG5JJJJJJJJJJJJJJ5GBBBBGJJJG#?
          J#GJJJJJJJY555YYJJJJJJYY555YJYGPYJJG#J
           7BB5JJJJJJJJY5555555555YJJJJJJJJ5BB7
            :YBG5JJJJJJJJJJJJJJJJJJJJJJJJ5GBY:
              ^JGBPYJJJJJJJJJJJJJJJJJJYPBGJ^
                .!YPGGP55YYYJJYYY55PGGPY!.
                   .:!?Y5PPPGGPPP5Y?!:.
                          ......
    */
}