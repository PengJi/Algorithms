/**
 * 55. 跳跃游戏
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 判断你是否能够到达最后一个位置。
 * 
 * https://leetcode-cn.com/problems/jump-game/
 */

class Solution {
public:
    // 贪心算法，从左向右每次
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    bool canJump(vector<int>& nums) {
        int maxIdx=0;  // 记录可跳的最远下标
        
        for(int i=0; i<nums.size(); i++){
            if(i > maxIdx) return false;  // 走不到该下标
            maxIdx = max(maxIdx, i + nums[i]);
        }

        return true;
    }

    // 贪心算法，从右向左遍历
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    bool canJump(vector<int>& nums) {
        int lastIndex = nums.size()-1;
        for(int i=lastIndex; i>=0; i--){
            if(i + nums[i] >= lastIndex){
                lastIndex = i;
            }
        }

        return lastIndex == 0;
    }
};
