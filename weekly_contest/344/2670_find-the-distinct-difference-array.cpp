/**
 * 2670. 找出不同元素数目差数组
 * https://leetcode.cn/problems/find-the-distinct-difference-array/
*/
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        const int n = nums.size();
        unordered_set<int> seen;
        vector<int> suf(n + 1);

        suf[n] = 0;

        for (int i = n - 1; i >= 1; i--) {
            suf[i] = suf[i + 1];
            if (seen.find(nums[i]) == seen.end()) {
                seen.insert(nums[i]);
                ++suf[i];
            }
        }

        seen.clear();
        int pre = 0;

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (seen.find(nums[i]) == seen.end()) {
                ++pre;
                seen.insert(nums[i]);
            }

            ans[i] = pre - suf[i + 1];
        }

        return ans;
    }
};
