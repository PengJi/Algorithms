/**
 * 2750. 将数组划分成若干好子数组的方式
 * https://leetcode.cn/problems/ways-to-split-array-into-good-subarrays/description/
*/

#define LL long long

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const int n = nums.size();
        const int mod = 1000000007;

        int ans = 1, prev = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 1)
                continue;

            if (prev != -1)
                ans = (LL)(ans) * (i - prev) % mod;

            prev = i;
        }

        if (prev == -1)
            return 0;

        return ans;
    }
};
