/**
 * 55. 跳跃游戏
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

class Solution {
public:
    // 贪心算法：对于某一个位置，判断能够到达该位置
    bool canJump(vector<int>& nums) {
        int jump_max = 0;
        for(int i = 0; i < nums.size(); i++) {
            // 如果能跳跃的最远距离小于当前的位置，则一定跳不到终点
            if(jump_max < i) return false;
            jump_max = max(jump_max, i + nums[i]);
        }

        return true;
    }
};
