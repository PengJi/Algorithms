/**
 * 5787. 最佳运动员的比拼回合
 * https://leetcode-cn.com/problems/the-earliest-and-latest-rounds-where-players-compete/
 */

const int N = 30;

bool f[N][N][N];

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/1347630/
    vector<int> earliestAndLatest(int n, int a, int b) {
        memset(f, 0, sizeof f);
        f[n][a - 1][n - b] = true;
        for (int k = n; k > 1; k = (k + 1) / 2)
            for (int x = 0; x <= n; x ++ )
                for (int y = 0; y <= n; y ++ )
                    if (f[k][x][y]) {
                        int m = (k + 1) / 2, m2 = k - m;
                        if (y >= m2) {
                            int z = k - x - y - 2;
                            for (int i = 0; i <= x; i ++ )
                                for (int j = 0; j <= z; j ++ )
                                    f[m][i][j + x - i + y - m2] = true;
                        } else if (x >= m2) {
                            int z = k - x - y - 2;
                            for (int i = 0; i <= y; i ++ )
                                for (int j = 0; j <= z; j ++ )
                                    f[m][j + y - i + x - m2][i] = true;
                        } else if (x < y) {
                            int z = y - x - 1;
                            for (int i = 0; i <= x; i ++ )
                                for (int j = 0; j <= z; j ++ )
                                    f[m][i][x - i + j] = true;
                        } else if (x > y) {
                            int z = x - y - 1;
                            for (int i = 0; i <= y; i ++ )
                                for (int j = 0; j <= z; j ++ )
                                    f[m][y - i + j][i] = true;
                        }
                    }

        int r1 = INT_MAX, r2 = INT_MIN;
        for (int k = n, t = 1; k > 1; k = (k + 1) / 2, t ++ )
            for (int i = 0; i <= n; i ++ )
                if (f[k][i][i]) {
                    r1 = min(r1, t);
                    r2 = max(r2, t);
                }
        return {r1, r2};
    }
};
