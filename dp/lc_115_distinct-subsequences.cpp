/**
 * 115. 不同的子序列
 * https://leetcode-cn.com/problems/distinct-subsequences/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/distinct-subsequences/solution/dong-tai-gui-hua-by-powcai-5/
    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(t.size() + 1, vector<long long>(s.size() + 1, 0));

        for (int i = 0; i < s.size() + 1; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < t.size() + 1; i++) {
            for (int j = 1; j < s.size() + 1; j++) {
                if (t[i - 1] == s[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }

        return dp[t.size()][s.size()];
    }
};
