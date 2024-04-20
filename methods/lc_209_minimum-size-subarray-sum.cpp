/**
 * 209. 长度最小的子数组
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 */

class Solution {
public:
    // 双指针
    // O(n)/O(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int left = 0, right = 0;
        int sum = 0;

        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= target) {
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        return res == INT_MAX ? 0 : res;
    }
};
