/**
 * 2841. 几乎唯一子数组的最大和
 * https://leetcode.cn/problems/maximum-sum-of-almost-unique-subarray/description/
*/
#define LL long long

class Solution {
public:
    LL maxSum(vector<int>& nums, int m, int k) {
        const int n = nums.size();

        LL ans = 0, tot = 0;
        unordered_map<int, int> seen;

        for (int i = 0; i < k - 1; i++) {
            ++seen[nums[i]];
            tot += nums[i];
        }

        for (int i = k - 1; i < n; i++) {
            ++seen[nums[i]];
            tot += nums[i];

            if (seen.size() >= m)
                ans = max(ans, tot);

            int v = nums[i - k + 1];
            tot -= v;
            --seen[v];
            if (seen[v] == 0)
                seen.erase(v);
        }

        return ans;
    }
};
