/**
 * 2735. 收集巧克力
 * https://leetcode.cn/problems/collecting-chocolates/description/
*/

#define LL long long

class Solution {
public:
    LL minCost(vector<int>& nums, int x) {
        const int n = nums.size();

        vector<vector<int>> cost(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            cost[i][0] = nums[i];
            for (int j = 1; j < n; j++)
                cost[i][j] = min(cost[i][j - 1], nums[(i + j) % n]);
        }

        LL ans = INT64_MAX;
        for (int j = 0; j < n; j++) {
            LL c = 0;
            for (int i = 0; i < n; i++)
                c += cost[i][j];

            ans = min(ans, c + (LL)(x) * j);
        }

        return ans;
    }
};
