/**
 * 2908. 元素和最小的山形三元组 I
 * https://leetcode.cn/problems/minimum-sum-of-mountain-triplets-i/description/
*/
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        const int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    if (nums[i] < nums[j] && nums[j] > nums[k])
                        ans = min(ans, nums[i] + nums[j] + nums[k]);

        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};
