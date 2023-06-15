/**
 * 2656. K 个元素的最大和
 * https://leetcode.cn/problems/maximum-sum-with-exactly-k-elements/
*/
class Solution {
public:
    // 贪心
    int maximizeSum(vector<int>& nums, int k) {
        const int n = nums.size();
        int m = nums[0];

        for (int i = 1; i < n; i++)
            if (m < nums[i])
                m = nums[i];

        return (m + m + k - 1) * k / 2;
    }
};
