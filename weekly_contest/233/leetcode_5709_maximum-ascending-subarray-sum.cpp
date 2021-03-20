/**
 * 5709. 最大升序子数组和
 * https://leetcode-cn.com/contest/weekly-contest-233/problems/maximum-ascending-subarray-sum/
 */

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int tmp = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                tmp += nums[i];
                res = max(res, tmp);
            } else {
                tmp = nums[i];
                res = max(res, nums[i]);
            }
        }
        
        return res;
    }
};
