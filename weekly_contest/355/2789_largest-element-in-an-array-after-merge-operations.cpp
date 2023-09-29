/**
 * 2789. 合并后数组中的最大元素
 * https://leetcode.cn/problems/largest-element-in-an-array-after-merge-operations/description/
*/
#define LL long long

class Solution {
public:
    // 贪心
    LL maxArrayValue(vector<int>& nums) {
        const int n = nums.size();

        LL ans = nums[n - 1], prev = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= prev) prev += nums[i];
            else prev = nums[i];

            ans = max(ans, prev);
        }

        return ans;
    }
};
