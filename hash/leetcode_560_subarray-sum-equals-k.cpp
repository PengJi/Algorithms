/**
 * 560. 和为K的子数组
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 * 
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/
 */

class Solution {
public:
    // 前缀和 + 哈希表优化
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;

        unordered_map<int, int> mp;  // 键为前连续n个元素的和，值为次数
        mp[0] = 1;
        int res = 0, pre = 0;

        for(auto num : nums) {
            pre += num;
            if(mp.find(pre-k) != mp.end()) res += mp[pre-k];
            mp[pre]++;
        }

        return res;
    }

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
};
