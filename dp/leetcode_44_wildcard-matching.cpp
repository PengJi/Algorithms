/**
 * 44. 通配符匹配
 * 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 * 
 * https://leetcode-cn.com/problems/wildcard-matching/
 */

class Solution {
public:
    // dp
    // https://leetcode-cn.com/problems/wildcard-matching/solution/tong-pei-fu-pi-pei-by-leetcode-solution/
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[0][0] = true;

        for(int i = 1; i <= n; ++i) {
            if(p[i - 1] == '*') {
                dp[0][i] = true;
            } else {
                break;
            }
        }

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] | dp[i-1][j];
                } else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }

        return dp[m][n];
    }
};
