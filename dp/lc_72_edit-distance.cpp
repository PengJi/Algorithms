/**
 * 72. 编辑距离
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 你可以对一个单词进行如下三种操作：
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符

 * https://leetcode-cn.com/problems/edit-distance/
 */

class Solution {
public:
    // 动态规划
    // 时间复杂度：O(mn)
    // 空间复杂度：O(mn)
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // 有一个字符串为空串
        if (n * m == 0) return n + m;

        // DP 数组
        int dp[n + 1][m + 1];

        // 边界状态初始化
        for (int i = 0; i < n + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            dp[0][j] = j;
        }

        // 计算所有 DP 值
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int left = dp[i - 1][j] + 1;
                int down = dp[i][j - 1] + 1;
                int left_down = dp[i - 1][j - 1];

                // 按照两种情况判断，当前字符相同和当前字符相同
                // 如果当前字符不相同
                if (word1[i - 1] != word2[j - 1]) left_down += 1;

                // 包含当前字符相同的情形
                dp[i][j] = min(left, min(down, left_down));
            }
        }
        return dp[n][m];
    }
};
