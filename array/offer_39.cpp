/**
 * 剑指 Offer 39. 数组中出现次数超过一半的数字
 * https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
 */

class Solution {
public:
    // 遍历
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], cnt = 1;  // 当前数字，出现的次数
        for(int i = 1; i < nums.size(); i++) {
            if(cnt == 0) {  // 出现次数为0，则重置当前数字
                ans = nums[i];
                cnt = 1;
            } else if(ans == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }

        return ans;
    }
};
