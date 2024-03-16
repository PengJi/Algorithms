/**
 * 162. 寻找峰值
 * https://leetcode-cn.com/problems/find-peak-element/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/258/
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};
