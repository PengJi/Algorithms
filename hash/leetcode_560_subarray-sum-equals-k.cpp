/**
 * 560. 和为K的子数组
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/
 */

class Solution {
public:
    // 枚举
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); ++start) {
            int sum = 0;
            for (int end = start; end >= 0; --end) {
                sum += nums[end];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }

    // 前缀和 + 哈希表优化
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) count += mp[pre - k];
            mp[pre]++;
        }
        return count;
    }
};