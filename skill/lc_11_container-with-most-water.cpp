/**
 * 11. 盛最多水的容器
 * https://leetcode-cn.com/problems/container-with-most-water/
 */

class Solution {
public:
    // 双指针法
    // O(n)/O(1)
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;

        while (left < right) {
            res = max(res, (right - left) * min(height[left], height[right]));
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return res;
    }
};
