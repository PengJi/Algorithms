/**
 * 1685. 有序数组中差绝对值之和
 * https://leetcode-cn.com/problems/sum-of-absolute-differences-in-a-sorted-array/
 */

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pre(n+1);

        for(int i = 1; i <= n; i++) {
            pre[i] = pre[i-1] + nums[i-1];
        }

        for(int i = 0; i < n; i++)
            res[i] = i * nums[i] - pre[i] + (pre[n] - pre[i+1]) - (n - i - 1) * nums[i];

        return res;
    }
};
