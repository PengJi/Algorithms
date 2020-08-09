/**
 * 5486. 切棍子的最小成本
 * https://leetcode-cn.com/problems/minimum-cost-to-cut-a-stick/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/minimum-cost-to-cut-a-stick/solution/dong-tai-gui-hua-di-gui-ji-yi-hua-sou-suo-by-time-/
    // 为了方便实现，
    // dp[l][r] 代表 切割以 cuts[l], cuts[r] 为左右端点的木棍的最小花费
    int dp[103][103];

    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        // 向 cuts 中加入 0 和 n。
        // 这不会影响答案，因为我们不会从这两处切割。
        return dfs(0, cuts.size()-1, cuts);
    }

    int dfs(int l, int r, const vector<int>& cuts) {
        // 保存已经计算过的答案，避免子问题的重复计算
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        // l+1 == r 时，说明不用再切了。
        if(l+1 == r) {
            dp[l][r] = 0;
            return 0;
        }
        // 枚举切割的地方，记录最优解。
        for(int i = l+1; i < r; i++) {
            int cost = dfs(l, i, cuts) + dfs(i, r, cuts) + cuts[r] - cuts[l];;
            if(dp[l][r] == -1 || dp[l][r] > cost) {
                dp[l][r] = cost;
            }
        }

        return dp[l][r];
    }
};
