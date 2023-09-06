/**
 * 2765. 最长交替子序列
 * https://leetcode.cn/problems/longest-alternating-subarray/
*/

class Solution {
public:
    // 双指针
    int alternatingSubarray(vector<int>& nums) {
        const int n = nums.size();

        int ans = -1;
        int i = 1;

        while (1) {
            while (i < n && nums[i] - nums[i - 1] != 1)
                ++i;

            if (i >= n)
                break;

            int j = i + 1;
            while (j < n && nums[j] - nums[j - 1] == ((i - j) % 2 ? -1 : 1))
                ++j;

            ans = max(ans, j - i + 1);

            i = j;
        }

        return ans;
    }
};
