/**
 * 5780. 删除一个元素使数组严格递增
 * https://leetcode-cn.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
 */

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            bool flag = false;
            int last = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(nums[j] <= last) flag = true;
                last = nums[j];
            }
            if(!flag) return true;
        }
        return false;
    }
};
