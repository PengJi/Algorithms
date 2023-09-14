/**
 * 2763. 所有子数组中不平衡数字之和
 * https://leetcode.cn/problems/sum-of-imbalance-numbers-of-all-subarrays/description/
*/

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        const int n = nums.size();
        unordered_set<int> seen;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            seen.clear();

            seen.insert(nums[i]);
            int cnt = 0;

            for (int j = i + 1; j < n; j++) {
                if (seen.find(nums[j]) != seen.end()) {
                    ans += cnt;

                    continue;
                }

                ++cnt;
                if (seen.find(nums[j] + 1) != seen.end()) --cnt;
                if (seen.find(nums[j] - 1) != seen.end()) --cnt;

                ans += cnt;
                seen.insert(nums[j]);
            }
        }

        return ans;
    }
};
