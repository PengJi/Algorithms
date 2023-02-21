/**
 * 2514. 统计同位异构字符串数目
 * https://leetcode.cn/problems/count-anagrams/
*/

#define LL long long

const int mod = 1000000007;

class Solution {
    vector<LL> fact;

private:
    LL power(int x, int y) {
        LL tot = 1, p = x;

        for (; y; y >>= 1) {
            if (y & 1)
                tot = tot * p % mod;

            p = p * p % mod;
        }

        return tot;
    }

    LL solve(const string &w) {
        const int m = w.size();

        vector<int> seen(26, 0);
        for (char c : w)
            seen[c - 'a']++;

        LL res = fact[m];

        for (int i = 0; i < 26; i++)
            res = res * power(fact[seen[i]], mod - 2) % mod;

        return res;
    }

public:
    int countAnagrams(string s) {
        const int n = s.size();

        fact.resize(n + 1);
        fact[0] = 1;

        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % mod;

        LL ans = 1;

        string w;
        for (int i = 0; i <= n; i++) {
            if (i < n && s[i] != ' ') {
                w += s[i];

                continue;
            }

            ans = ans * solve(w) % mod;

            w.clear();
        }

        return ans;
    }
};
