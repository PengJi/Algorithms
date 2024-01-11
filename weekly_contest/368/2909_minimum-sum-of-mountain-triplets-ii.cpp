/**
 * 2909. 元素和最小的山形三元组 II
 * https://leetcode.cn/problems/minimum-sum-of-mountain-triplets-ii/description/
*/
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        const int n = nums.size();

        vector<int> suf(n);
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = min(suf[i + 1], nums[i]);

        int ans = INT_MAX;
        int pre = nums[0];

        for (int i = 1; i < n - 1; i++) {
            if (pre < nums[i] && nums[i] > suf[i + 1])
                ans = min(ans, pre + nums[i] + suf[i + 1]);

            pre = min(pre, nums[i]);
        }

        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};
