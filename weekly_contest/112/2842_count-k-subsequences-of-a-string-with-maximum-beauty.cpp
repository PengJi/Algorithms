/**
 * https://leetcode.cn/problems/count-k-subsequences-of-a-string-with-maximum-beauty/description/
*/
class Solution {
    const long long MOD = 1e9 + 7;

    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) res = res * x % MOD;
            x = x * x % MOD;
        }
        return res;
    }

    long long comb(long long n, int k) {
        auto res = n;
        for (int i = 2; i <= k; i++)
            res = res * --n / i;
        return res % MOD;
    }

public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int cnt[26]{};
        for (char c: s)
            cnt[c - 'a']++;
        map<int, int> cc;
        for (int c: cnt)
            if (c) cc[-c]++;

        long long ans = 1;
        for (auto [c, num]: cc) {
            if (num >= k)
                return ans * pow(-c, k) % MOD * comb(num, k) % MOD;
            ans = ans * pow(-c, num) % MOD;
            k -= num;
        }
        return 0;
    }
};
