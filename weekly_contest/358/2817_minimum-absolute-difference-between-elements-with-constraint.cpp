/**
 * 2817. 限制条件下元素之间的最小绝对差
 * https://leetcode.cn/problems/minimum-absolute-difference-between-elements-with-constraint/description/
*/
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        const int n = nums.size();

        int ans = INT_MAX;
        set<int> h;

        for (int i = x; i < n; i++) {
            h.insert(nums[i - x]);
            auto it = h.lower_bound(nums[i]);

            if (it != h.end())
                ans = min(ans, abs(*it - nums[i]));

            if (it != h.begin()) {
                --it;
                ans = min(ans, abs(*it - nums[i]));
            }
        }

        return ans;
    }
};
