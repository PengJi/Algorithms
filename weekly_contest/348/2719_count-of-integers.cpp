/**
 * 2719. 统计整数数目
 * https://leetcode.cn/problems/count-of-integers/description/
*/

#define LL long long

const int mod = 1000000007;
const int L = 30, S = 410;

class Solution {
private:
    int f[L][S], g[L][S];

    void init(int n, int m) {
        f[0][0] = g[0][0] = 1;

        for (int j = 1; j <= m; j++) {
            f[0][j] = 1;
            g[0][j] = (g[0][j - 1] + f[0][j]) % mod;
        }

        for (int i = 1; i < n; i++) {
            f[i][0] = g[i][0] = 1;

            for (int j = 1; j <= m; j++) {
                f[i][j] = (f[i][j - 1] + f[i - 1][j]) % mod;

                if (j >= 10)
                    f[i][j] = (f[i][j] - f[i - 1][j - 10]) % mod;

                g[i][j] = (g[i][j - 1] + f[i][j]) % mod;
            }
        }
    }

    int solve(string num, int sum) {
        const int n = num.size();

        int res = 0;
        for (int i = 0; i < n; i++) {
            int x = num[i] - '0';

            res = (res + g[n - i - 1][sum]) % mod;
            if (sum >= x)
                res = (res - g[n - i - 1][sum - x]) % mod;

            sum -= x;
            if (sum < 0)
                return res;
        }

        return res + 1;
    }

public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        init(num2.size(), max_sum);

        int ans = 0;

        ans = (ans + solve(num2, max_sum)) % mod;
        ans = (ans - solve(num2, min_sum - 1)) % mod;
        ans = (ans - solve(num1, max_sum)) % mod;
        ans = (ans + solve(num1, min_sum - 1)) % mod;

        int tot = 0;
        for (char c : num1)
            tot += c - '0';

        if (min_sum <= tot && tot <= max_sum)
            ++ans;

        return (ans + mod) % mod;
    }
};
