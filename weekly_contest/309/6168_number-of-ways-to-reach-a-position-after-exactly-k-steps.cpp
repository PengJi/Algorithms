const int N = 2010, MOD = 1e9 + 7;

int f[1010][N];

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        startPos += 500, endPos += 500;
        memset(f, 0, sizeof f);
        f[0][startPos] = 1;
        for (int i = 1; i <= k; i ++ )
            for (int j = 0; j < N; j ++ ) {
                if (j) f[i][j] = f[i - 1][j - 1];
                if (j + 1 < N) f[i][j] = (f[i][j] + f[i - 1][j + 1]) % MOD;
            }
        return f[k][endPos];
    }
};
