/**
 * 152. 乘积最大子数组
 * https://leetcode-cn.com/problems/maximum-product-subarray/
 */

class Solution {
public:
    // 动态规划：
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;

        int res = -2147483648;
        int tmpMax = 1, tmpMin = 1;
        for(int i = 0; i < len; i++){
            if(nums[i] < 0){
                swap(tmpMax, tmpMin);
            }
            tmpMax = max(tmpMax * nums[i], nums[i]);
            tmpMin = min(tmpMin * nums[i], nums[i]);

            res = max(res, tmpMax);
        }

        return res;
    }
};