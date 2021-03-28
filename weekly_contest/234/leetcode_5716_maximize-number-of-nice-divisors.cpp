/**
 * 5716. 好因子的最大数目
 * https://leetcode-cn.com/problems/maximize-number-of-nice-divisors/
 */

class Solution {
public:
    typedef long long LL;
    const int MOD = 1e9 + 7;

    int qmi(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = (LL)res * a % MOD;
            a = (LL)a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    // https://www.acwing.com/activity/content/code/content/1045620/
    // 快速幂
    int maxNiceDivisors(int m) {
        if (m <= 3) return m;
        if (m % 3 == 0) return qmi(3, m / 3);
        if (m % 3 == 1) return (LL)qmi(3, (m - 4) / 3) * 4 % MOD;
        return (LL)qmi(3, (m - 2) / 3) * 2 % MOD;
    }
};
