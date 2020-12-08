/**
 * 5620. 连接连续二进制数字
 * https://leetcode-cn.com/problems/concatenation-of-consecutive-binary-numbers/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/concatenation-of-consecutive-binary-numbers/solution/lian-jie-lian-xu-er-jin-zhi-shu-zi-by-ze-t40j/
    int concatenatedBinary(int n) {
        int mod = 1000000007;
        int ans = 0;
        int shift = 0;
        for (int i = 1; i <= n; ++i) {
            // if (131072 % i == 0) {
            if (!(i & (i - 1))) {
                ++shift;
            }
            ans = ((static_cast<long long>(ans) << shift) + i) % mod;
        }
        return ans;
    }
};
