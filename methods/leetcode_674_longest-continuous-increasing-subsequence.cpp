/**
 * 674. 最长连续递增序列
 * https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
 */

class Solution {
public:
    // 滑动窗口
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;

        int tmp = 0, res = 1;
        for(int i = 1; i < len; i++) {
            if(nums[i-1] > nums[1]) tmp = i;
            res = max(0, i-tmp+1);
        }

        return res;
    }
};
