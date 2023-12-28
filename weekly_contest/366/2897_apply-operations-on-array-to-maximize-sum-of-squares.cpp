/**
 * 2897. 对数组执行操作使平方和最大
 * https://leetcode.cn/problems/apply-operations-on-array-to-maximize-sum-of-squares/description/
*/
#define LL long long

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int mod = 1000000007;

        const int n = nums.size();
        vector<int> c(30, 0);
        for (int b = 0; b < 30; b++)
            for (int x : nums)
                if ((x >> b) & 1)
                    ++c[b];

        int ans = 0;
        for (int i = 0; i < k; i++) {
            int x = 0;
            for (int b = 0; b < 30; b++)
                if (c[b] > i)
                    x |= 1 << b;

            ans = (ans + (LL)(x) * x) % mod;
        }

        return ans;
    }
};
