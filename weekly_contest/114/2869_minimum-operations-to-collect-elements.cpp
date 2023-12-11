/**
 * 2869. 收集元素的最少操作次数
 * https://leetcode.cn/problems/minimum-operations-to-collect-elements/description/
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<bool> seen(k + 1, false);
        int cnt = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] <= k && !seen[nums[i]]) {
                ++cnt;

                seen[nums[i]] = true;
            }

            if (cnt == k)
                return n - i;
        }

        return n;
    }
};
