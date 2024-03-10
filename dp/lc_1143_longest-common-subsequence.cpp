/**
 * 1143. 最长公共子序列
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
 * 一个字符串的 子序列 是指这样一个新的字符串：
 * 它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
 * 两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
 *
 * https://leetcode-cn.com/problems/longest-common-subsequence/
 */

class Solution {
public:
    // 动态规划
    // 时间复杂度：O(mn)
    // 空间复杂度：O(mn)
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        if (len1 == 0 || len2 == 0) {
            return 0;
        }

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));  // DP table
        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[len1][len2];
    }
};

class Solution {
public:
    // 状态表示：f(i,j) 表示第一个字符串的前 i 个字符和第二个字符串的前 j 个字符的最长公共子序列。这里的字符串的下标假设从 1 开始。
    // 初始状态：f(0,j)=f(i,0)=0f(0,j)=f(i,0)=0，表示空串不和任何字符串有公共子序列。
    // 状态转移：1. 如果 s1(i)==s2(j) 则 f(i,j)=max(f(i−1,j),f(i,j−1),f(i−1,j−1)+1)f(i,j)，
    //          表示既可以忽视 s1(i)，也可以忽视 s2(j)，也可以让 s1(i) 和 s2(j) 匹配。
    //          2. 否则，f(i,j)=max(f(i−1,j),f(i,j−1)f(i,j)，表示只能忽视 s1(i) 或忽视 s2(j)。
    // 答案为：f(n, m)
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    f[i][j] = max(f[i - 1][j - 1] + 1, max(f[i - 1][j], f[i][j - 1]));
                } else {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }

        return f[n][m];
    }
};
