/**
 * 560. 和为 K 的子数组
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/
 */

class Solution {
public:
    // 前缀和 + 哈希表
    // 对原数组求前缀和后，一个和为 k 的子数组即为一对前缀和的差值为 k 的位置。
    // 遍历前缀和数组，用 unordered_map 哈希表记录每个前缀和出现的次数。
    // 特别地，初始时前缀和为 0 需要被额外记录一次。
    // 遍历过程中，对于当前前缀和 tot，累加之前 tot - k 前缀和出现的次数。
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];  // 可用一个变量代替，见下面算法

        unordered_map<int, int> mp;
        int res = 0;
        for (int i = 0; i <= n; i++) {
            res += mp[s[i] - k];
            mp[s[i]]++;
        }

        return res;
    }
};

class Solution {
public:
    // 前缀和 + 哈希表
    // 进一步降低空间复杂度
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;  // 注意

        for (auto& n : nums) {
            sum += n;
            res += mp[sum - k];
            mp[sum]++;
        }

        return res;
    }
};
