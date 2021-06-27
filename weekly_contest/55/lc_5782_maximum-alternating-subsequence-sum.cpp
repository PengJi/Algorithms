/**
 * 5782. 最大子序列交替和
 * https://leetcode-cn.com/problems/maximum-alternating-subsequence-sum/
 */

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        typedef long long LL;
        int n = nums.size();
        const LL INF = 1e15;
        vector<vector<LL>> f(n+1, vector<LL>(2, -INF));
        f[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            f[i][0] = max(f[i-1][0], f[i-1][1] - nums[i-1]);
            f[i][1] = max(f[i-1][1], f[i-1][0] + nums[i-1]);
        }

        return max(f[n][0], f[n][1]);
    }
};
