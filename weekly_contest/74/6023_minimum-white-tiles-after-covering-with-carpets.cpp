class Solution {
public:
    /* dp[i][j] 表示使用了i条地毯覆盖[0,j]的地板, 最小的白色砖块数 */
    /* dp[0][j], [0,j]一共的白色砖块数 */
    /* dp[i][j], dp[i][j] = min(dp[i][j-1] + floor[j], dp[i-1][j-carpetLen]) */
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> dp(numCarpets + 1, vector<int>(n));
        int cnt = 0;
        /* dp初始化 */
        for (int j = 0; j < n; j++) {
            cnt += (floor[j] - '0');
            dp[0][j] = cnt;
        }
        /* dp动态方程转移 */
        for (int i = 1; i <= numCarpets; i++) {
            for (int j = 0; j < n; j++) {
                if (j < carpetLen) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(dp[i][j - 1] + (floor[j] - '0'), 
                                   dp[i - 1][j - carpetLen]);
                }
            }
        }
        return dp[numCarpets][n - 1];
    }
};
