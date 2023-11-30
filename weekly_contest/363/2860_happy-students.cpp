/**
 * 2860. 让所有学生保持开心的分组方法数
 * https://leetcode.cn/problems/happy-students/description/
*/
class Solution {
public:
    // 贪心
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        const int n = nums.size();
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            if (i > 0 && i <= nums[i - 1])
                continue;

            if (i < n && i >= nums[i])
                continue;

            ++ans;
        }

        return ans;
    }
};
