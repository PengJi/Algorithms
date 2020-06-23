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
        if(nums.size() == 0) return 0;

        int tmp=0, res=1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] >= nums[i]) tmp = i;
            res = max(res, i-tmp+1);
        }

        return res;
    }
};