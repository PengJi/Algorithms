/**
 * 45. 跳跃游戏 II
 * https://leetcode-cn.com/problems/jump-game-ii/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/jump-game-ii/solution/tiao-yue-you-xi-ii-by-leetcode-solution/
    int jump(vector<int>& nums) {
        int maxPos = 0;
        int n = nums.size();
        int end = 0, step = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // 状态数组
        vector<int> f(n);

        for(int i = 1, j = 0; i < n; i++) {
            while(j + nums[j] < i) j++;
            f[i] = f[j] + 1;
        }

        return f[n-1];
    }
};
