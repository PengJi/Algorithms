/**
 * 10. 正则表达式匹配
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/
 */

class Solution {
public:
    // dp
    // https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if(i == 0) {
                return false;
            }
            if(p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[0][0] = true;
        for(int i = 0; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j-1] == '*') {
                    dp[i][j] |= dp[i][j-2];
                    if(matches(i, j-1)) {
                        dp[i][j] |= dp[i-1][j];
                    }
                } else {
                    if(matches(i, j)) {
                        dp[i][j] |= dp[i-1][j-1];
                    }
                }
            }
        }

        return dp[m][n];
    }
};
