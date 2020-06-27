/**
 * 62. 不同路径
 * https://leetcode-cn.com/problems/unique-paths/
 */

class Solution {
public:
    // 动态规划（一维空间）
    // 时间复杂度：O()
    // 空间复杂度：O()
    int uniquePaths(int m, int n) {
        int small=min(m, n);
        int large=max(m, n);
        vector<int> dp(small, 1);
        for(int i=1; i<large; i++){
            for(int j=1; j<small; j++) dp[j]+=dp[j-1]; 
        }
        return dp[small-1];
    }

    // 动态规划（二维空间）
    // 时间复杂度：
    // 空间复杂度：
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 1));
        // for(int i=0;i<n;i++) dp[0][i]=1;
        // for(int j=1;j<m;j++) dp[j][0]=1;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++) dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
        return dp[m-1][n-1];
    }
};