#include <bits/stdc++.h>

using namespace std;

class RabinKarpMatcher {
private:
    const long long MOD = 1e9 + 7;
    const long long X = 31;
    string s;
    vector<long long> prefixHashes; 

    long long getHash(const string& str) const {
        long long hash = 0;
        long long curX = 1;
        for (long long i = 0; i < str.size(); i++) {
            hash = (hash + (str[i] - 'a' + 1) * curX % MOD) % MOD;
            curX = (curX * X) % MOD;
        }
        return hash;
    }

    vector<long long> computePrefixHashes() const {
        vector<long long> hashes(s.size());
        long long curX = 1;
        for (long long i = 0; i < s.size(); i++) {
            hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
            if (i != 0) {
                hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
            }
            curX = (curX * X) % MOD;
        }
        return hashes;
    }

    vector<long long> findOccurrences(const string& t, long long smallHash) const {
        vector<long long> occurrences;
        long long t_size = t.size();
        for (long long i = 0; i <= s.size() - t_size; i++) {
            long long hashDif = prefixHashes[i + t_size - 1];
            if (i != 0) {
                hashDif = (hashDif - prefixHashes[i - 1] + MOD) % MOD;
            }
            long long adjustedSmallHash = (smallHash * powMod(X, i, MOD)) % MOD;
            if (adjustedSmallHash == hashDif) {
                occurrences.push_back(i);
            }
        }
        return occurrences;
    }

    bool containsSubstring(const string& t, long long smallHash) const {
        for (long long i = 0; i <= s.size() - t.size(); i++) {
            long long hashDif = prefixHashes[i + t.size() - 1];
            if (i != 0) {
                hashDif = (hashDif - prefixHashes[i - 1] + MOD) % MOD;
            }
            long long adjustedSmallHash = (smallHash * powMod(X, i, MOD)) % MOD;
            if (adjustedSmallHash == hashDif) {
                return true;
            }
        }
        return false;
    }

    long long powMod(long long base, long long exp, long long mod) const {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

public:
    RabinKarpMatcher(const string& inputString) : s(inputString) {
        prefixHashes = computePrefixHashes();
    }

    bool allSubstringsPresent(const vector<string>& substrings) {
        vector<bool> markedPositions(s.size(), false);

        for (const string& t : substrings) {
            long long smallHash = getHash(t);
            if (!containsSubstring(t, smallHash)) {
                return false;  
            }

            vector<long long> occurrences = findOccurrences(t, smallHash);
            for (long long index : occurrences) {
                for (long long offset = 0; offset < t.size(); offset++) {
                    markedPositions[index + offset] = true;
                }
            }
        }

        for (bool marked : markedPositions) {
            if (!marked) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s;
    cin >> s;
    long long n;
    cin >> n;
    vector<string> substrings(n);
    for (long long i = 0; i < n; i++) {
        cin >> substrings[i];
    }

    RabinKarpMatcher matcher(s);
    if (matcher.allSubstringsPresent(substrings)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
