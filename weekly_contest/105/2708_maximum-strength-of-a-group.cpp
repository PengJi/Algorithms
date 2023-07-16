/**
 * 2708. 一个小组的最大实力值
 * https://leetcode.cn/problems/maximum-strength-of-a-group
*/

#define LL long long

class Solution {
public:
    LL ans;

    // 递归回溯
    void solve(int i, LL s, const vector<int> &nums) {
        if (i == nums.size()) {
            ans = max(ans, s);
            return;
        }

        solve(i + 1, s, nums);
        solve(i + 1, s == INT64_MIN ? nums[i] : s * nums[i], nums);
    }

    LL maxStrength(vector<int>& nums) {
        ans = INT64_MIN;

        solve(0, INT64_MIN, nums);

        return ans;
    }
};
