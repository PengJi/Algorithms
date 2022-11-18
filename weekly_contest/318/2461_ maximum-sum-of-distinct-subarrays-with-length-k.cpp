/**
 * 2461. 长度为 K 子数组中的最大和
 * https://leetcode.cn/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
*/
#define LL long long

class Solution {
public:
    // 滑动窗口
    // 使用哈希表统计子数组中每个数字出现的次数。
    // 采用滑动窗口，每次滑动一个位置，同时更新哈希表。
    // 如果哈希表中元素的个数等于 kk，则更新答案。
    LL maximumSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int, int> seen;

        LL sum = 0;
        for (int i = 0; i < k - 1; i++) {
            sum += nums[i];
            ++seen[nums[i]];
        }

        LL ans = 0;
        for (int i = k - 1; i < n; i++) {
            sum += nums[i];
            ++seen[nums[i]];

            if (seen.size() == k)
                ans = max(ans, sum);

            sum -= nums[i - k + 1];
            --seen[nums[i - k + 1]];
            if (seen[nums[i - k + 1]] == 0)
                seen.erase(nums[i - k + 1]);
        }

        return ans;
    }
};
