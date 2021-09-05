/**
 * 5846. 找到数组的中间位置
 * https://leetcode-cn.com/problems/find-the-middle-index-in-array/
 */
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            int l = i - 1, left = 0;
            int r = i + 1, right = 0;
            while(l >= 0) {
                left += nums[l];
                l--;
            }
            while(r <= len -1) {
                right += nums[r];
                r++;
            }
            if(left == right) return i;
        }
        
        return -1;
    }
};
