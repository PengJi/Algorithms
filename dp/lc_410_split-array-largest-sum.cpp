/**
 * 410. 分割数组的最大值
 * https://leetcode.cn/problems/split-array-largest-sum/
 */

class Solution {
public:
    using ll = long long;

    // https://leetcode.com/problems/split-array-largest-sum/discuss/89873/Binary-Search-C%2B%2B-Solution
    int splitArray(vector<int>& nums, int m) {
        ll left = 0, right = 0;
        for (auto& num : nums) {
            left = max(left, (ll)num);
            right += num;
        }
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            if (canSplit(nums, m, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

    bool canSplit(vector<int>& nums, int m, ll sum) {
        int c = 1;
        ll s = 0;
        for (auto& num : nums) {
            s += num;
            if (s > sum) {
                s = num;
                ++c;
            }
        }
        return c <= m;
    }
};
