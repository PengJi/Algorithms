/**
 * 2760. 最长奇偶子数组
 * https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/description/
*/

class Solution {
public:
    // 双指针
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        const int n = nums.size();

        int ans = 0;
        int l = 0;
        while (l < n) {
            if (nums[l] % 2 != 0 || nums[l] > threshold) {
                ++l;

                continue;
            }

            int r = l + 1;
            while (r < n) {
                if (nums[r] > threshold || nums[r - 1] % 2 == nums[r] % 2)
                    break;

                ++r;
            }

            ans = max(ans, r - l);

            l = r;
        }

        return ans;
    }
};
