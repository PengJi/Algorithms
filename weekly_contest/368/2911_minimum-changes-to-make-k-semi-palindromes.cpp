/**
 * 2911. 得到 K 个半回文串的最少修改次数
 * https://leetcode.cn/problems/minimum-changes-to-make-k-semi-palindromes/description/
*/
const int N = 210;

class Solution {
private:
    int cost[N][N], c[N][N], f[N][N];

public:
    int minimumChanges(string s, int k) {
        const int n = s.size();

        memset(c, 0x3f, sizeof(c));
        for (int d = 1; d < n; d++) {
            for (int i = n - 1; i >= 0; i--) {
                cost[i][i] = 0;
                if (i + d < n)
                    cost[i][i + d] = s[i] != s[i + d];
                for (int j = i + 2 * d; j < n; j += d)
                    cost[i][j] = cost[i + d][j - d] + (bool)(s[i] != s[j]);
            }

            for (int i = 0; i < n - d; i++)
                for (int j = i + d; j < n; j++) {
                    int len = j - i + 1;
                    if (len % d != 0)
                        continue;

                    int t = 0;
                    for (int x = 0; x < d; x++)
                        t += cost[i + x][i + len - d + x];
                    c[i][j] = min(c[i][j], t);
                }
        }

        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++)
                for (int p = 0; p < i; p++)
                    f[i][j] = min(f[i][j], f[p][j - 1] + c[p][i - 1]);

        return f[n][k];
    }
};
