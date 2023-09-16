/**
 * 2770
 * https://leetcode.cn/problems/maximum-number-of-jumps-to-reach-the-last-index/description/
*/

class Solution {
public:
    // 动态规划
    int maximumJumps(vector<int>& nums, int target) {
        const int n = nums.size();

        vector<int> f(n, INT_MIN);

        f[0] = 0;
        for (int i = 1, j = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (abs(nums[i] - nums[j]) <= target)
                    f[i] = max(f[i], f[j] + 1);

        if (f[n - 1] < 0)
            return -1;

        return f[n - 1];
    }
};
