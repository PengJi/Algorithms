/**
 * 560. 和为K的子数组
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/
 */

class Solution {
public:
    // 前缀和
    // https://zhuanlan.zhihu.com/p/107778275
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0, pre_sum = 0;
        for(auto num : nums) {
            pre_sum += num;
            if(mp.find(pre_sum-k) != mp.end()) ans += mp[pre_sum-k];
            mp[pre_sum]++;
        }

        return ans;
    }
};
