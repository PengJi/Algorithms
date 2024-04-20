/**
 * 228. 汇总区间
 * https://leetcode-cn.com/problems/summary-ranges/
 */

class Solution {
public:
    // 双指针
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;  // 区间的左右端点
        vector<string> res;

        while (right < n) {
            while (right + 1 < n) {
                if (nums[right] + 1 == nums[right + 1]) {
                    right++;
                } else {
                    break;
                }
            }

            if (left == right) {
                res.push_back(to_string(nums[left]));
            } else {
                res.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
            }

            right++;
            left = right;
        }

        return res;
    }
};
