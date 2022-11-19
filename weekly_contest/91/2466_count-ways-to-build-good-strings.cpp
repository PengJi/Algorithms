/**
 * 2466. 统计构造好字符串的方案数
 * https://leetcode.cn/problems/count-ways-to-build-good-strings/description/
*/

const int mod = 1000000007;

class Solution {
public:
    // 动态规划
    // 状态表示 f(i)f(i) 为长度为 ii 的不同字符串的数目。
    // 初始状态 f(0)=1f(0)=1，其余为 00 待定。
    // 转移方程 f(i)f(i)，
    // 如果 i≥zero，f(i)=f(i)+f(i−zero)；
    // 如果 i≥one，f(i)=f(i)+f(i−one)。
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;

        vector<int> f(high + 1, 0);
        f[0] = 1;

        for (int i = 1; i <= high; i++) {
            if (i >= zero) f[i] = (f[i] + f[i - zero]) % mod;
            if (i >= one) f[i] = (f[i] + f[i - one]) % mod;

            if (i >= low)
                ans = (ans + f[i]) % mod;
        }

        return ans;
    }
};
