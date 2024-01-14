/**
 * 2913. 子数组不同元素数目的平方和 I
 * https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-i/description/
*/
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int n = nums.size();
        const int mod = 1000000007;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            int c = 0;
            for (int j = i; j < n; j++) {
                if (seen.find(nums[j]) == seen.end()) {
                    ++c;
                    seen.insert(nums[j]);
                }
                ans = (ans + c * c) % mod;
            }
        }

        return ans;
    }
};
