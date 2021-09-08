/**
 * 1929. 数组串联
 * https://leetcode-cn.com/problems/concatenation-of-array/
 */

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len*2);
        for(int i = 0; i < len; i++) {
            ans[i] = nums[i];
            ans[i + len] = nums[i];
        }
        
        return ans;
    }
};
