/**
 * 2518. 好分区的数目
 * https://leetcode.cn/problems/number-of-great-partitions/description/
*/

#define LL long long

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int n = nums.size();
        const int mod = 1000000007;

        LL sum = 0, ans = 1;

        vector<int> f(k, 0);
        f[0] = 1;

        for (int i = 0; i < n; i++) {
            ans = ans * 2 % mod;
            sum += nums[i];

            for (int j = k - 1; j >= nums[i]; j--)
                f[j] = (f[j] + f[j - nums[i]]) % mod;
        }

        if (sum < 2 * k)
            return 0;

        for (int j = 0; j < k; j++)
            ans = (ans - 2 * f[j]) % mod;

        return (ans + mod) % mod;
    }
};
