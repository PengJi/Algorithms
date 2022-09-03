/**
 * 11. 盛最多水的容器
 * https://leetcode-cn.com/problems/container-with-most-water/
 */

class Solution {
public:
    // 双指针法
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return 0;

        int left = 0, right = height.size()-1;
        int max = 0, area = 0;

        while(left < right) {
            if(height[left] <= height[right]) {
                area = height[left] * (right - left);
                left++;
            } else {
                area = height[right] * (right - left);
                right--;
            }

            if(area > max) max = area;
        }

        return max;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int res = INT_MIN;
        while(l < r) {
            res = max(res, (r-l) * min(height[l], height[r]));
            if(height[l] < height[r]) l++;
            else r--;
        }

        return res;
    }
};

