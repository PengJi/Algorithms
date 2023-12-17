/**
 * 2875. 无限数组的最短子数组
 * https://leetcode.cn/problems/minimum-size-subarray-in-infinite-array/description/
*/
#define LL long long

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        const int n = nums.size();

        LL sum = 0;
        for (int x : nums)
            sum += x;

        int lp = target / sum;
        target %= sum;

        nums.insert(nums.end(), nums.begin(), nums.end());

        LL t = 0;
        int ans = INT_MAX;
        for (int i = 0, j = 0; i < 2 * n; i++) {
            t += nums[i];
            while (j <= i && t > target) {
                t -= nums[j];
                j++;
            }

            if (t == target)
                ans = min(ans, i - j + 1);
        }

        if (ans == INT_MAX)
            return -1;

        return ans + lp * n;
    }
};
