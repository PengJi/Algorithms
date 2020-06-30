/**
 * 42. 接雨水
 * https://leetcode-cn.com/problems/trapping-rain-water/
 */

class Solution {
public:
    // 动态规划
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int trap(vector<int>& height) {
        int len = height.size();
        if(len == 0) return 0;

        vector<int> left_max(len);  // 左边最大高度
        left_max[0] = height[0];  
        for(int i = 1; i < len; i++) {
            left_max[i] = max(left_max[i-1], height[i]);
        }

        vector<int> right_max(len);  // 右边最大高度
        right_max[len-1] = height[len-1];
        for(int i = len-2; i > 0; i--) {
            right_max[i] = max(right_max[i+1], height[i]);
        }

        int res=0, ans=0;
        for(int i = 1; i < len-1; i++) {
            ans = min(left_max[i], right_max[i]);
            if(height[i] < ans) {
                res += (ans - height[i]);
            }
        }

        return res;
    }

    // 双指针法
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int trap(vector<int>& height) {
        int len = height.size();
        if(len == 0) return 0;

        int left = 0, right = len-1;
        int res = 0;
        int left_max = 0, right_max = height[len-1];

        while(left < right) {
            if(height[left] < height[right]) {
                left_max = max(left_max, height[left]);  // 当前位置左边的最大高度
                res += (left_max - height[left]);  // 当前位置可储水量
                left++;
            } else {
                right_max = max(right_max, height[right]);
                res += (right_max - height[right]);
                right--;
            }
        }

        return res;
    }
};
