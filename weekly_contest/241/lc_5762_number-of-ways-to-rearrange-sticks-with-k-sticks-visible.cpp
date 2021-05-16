/**
 * 5762. 恰有 K 根木棍可以看到的排列数目
 * https://leetcode-cn.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/
 */

typedef long long LL;

const int N = 1010, MOD = 1e9 + 7;

int f[N][N];

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/1240278/
    int rearrangeSticks(int n, int k) {
        f[0][0] = 1;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= k; j ++ )
                f[i][j] = (f[i - 1][j - 1] + (LL)(i - 1) * (f[i - 1][j])) % MOD;
        return f[n][k];
    }
};
