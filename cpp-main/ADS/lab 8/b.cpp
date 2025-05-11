#include <bits/stdc++.h>

using namespace std;

class Rabin_Karp {
private:
    const long long MOD = 1e9 + 7;
    const long long X = 31;

    long long getHash(string s){
        long long hash = 0;
        long long curX = 1;
        for (int i = 0; i < s.size(); i++){
            long long curHash = (s[i] - 'a' + 1) * curX % MOD;
            hash = (hash + curHash) % MOD;
            curX = (curX * X) % MOD;
        }
        return hash;
    }

    vector<long long> getPrefixHashes(string s){
        vector<long long> hashes(s.size());
        long long curX = 1;
        for (int i = 0; i < s.size(); i++){
            hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
            if (i != 0)
                hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
            curX = (curX * X) % MOD;
        }
        return hashes;
    }


public:
    void merge(const vector<int>& v1, const vector<int>& v2, int &cnt) {
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] > v2[j])
                ++j;
            else if (v1[i] < v2[j])
                ++i;
            else {
                ++cnt;
                ++i;
                ++j;
            }
        }
    }

    vector<int> rabinKarp(string s, string t){
        long long smallHash = getHash(t);
        vector<int> res;
        vector<long long> hashes = getPrefixHashes(s);
        for (int i = 0; i < s.size() - t.size() + 1; i++){
            long long hashDif = hashes[i + t.size() - 1];
            if (i != 0)
                hashDif -= hashes[i - 1];
            if (hashDif < 0)
                hashDif += MOD;
            if (i != 0)
                smallHash = (smallHash * X) % MOD;
            if (smallHash == hashDif)
                res.push_back(i);
        }
        return res;
    }
};

int main() {
    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    Rabin_Karp rk;  

    vector<int> positions1 = rk.rabinKarp(s1, t);
    vector<int> positions2 = rk.rabinKarp(s2, t);

    int commonCount = 0;
    rk.merge(positions1, positions2, commonCount);

    cout << commonCount << endl;

    return 0;
}
