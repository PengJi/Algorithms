/**
 * 2871. 将数组分割成最多数目的子数组
 * https://leetcode.cn/problems/split-array-into-maximum-number-of-subarrays/description/
*/
class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        const int n = nums.size();

        int t = INT_MAX;
        for (int x : nums)
            t &= x;

        if (t > 0)
            return 1;

        int ans = 0;
        for (int i = 0, c = INT_MAX; i < n; i++) {
            c &= nums[i];
            if (c == 0) {
                ++ans;
                c = INT_MAX;
            }
        }

        return ans;
    }
};
