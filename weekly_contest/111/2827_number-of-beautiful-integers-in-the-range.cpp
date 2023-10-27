/**
 * 2827. 范围中美丽整数的数目
 * https://leetcode.cn/problems/number-of-beautiful-integers-in-the-range/description/
*/
const int N = 10, K = 20;

class Solution {
private:
    int f[N][N][K], g[N][N][K];

    void init(int k) {
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));

        f[0][0][0] = f[1][0][0] = 1;
        for (int num = 1; num < 10; num++) {
            ++f[1][num % 2][num % k];
            ++g[1][num % 2][num % k];
        }

        for (int len = 1; len < N - 1; len++)
            for (int i = 0; i <= len; i++)
                for (int j = 0; j < k; j++)
                    for (int num = 0; num < 10; num++) {
                        if (num % 2 == 0) {
                            f[len + 1][i][(j * 10 + num) % k] += f[len][i][j];
                            g[len + 1][i][(j * 10 + num) % k] += g[len][i][j];
                        } else {
                            f[len + 1][i + 1][(j * 10 + num) % k] += f[len][i][j];
                            g[len + 1][i + 1][(j * 10 + num) % k] += g[len][i][j];
                        }
                    }
    }

    int solve(int x, int k) {
        if (x == 0)
            return 0;

        vector<int> nums;
        int power = 1;
        while (x >= 10) {
            nums.push_back(x % 10);
            x /= 10;
            power *= 10;
        }
        nums.push_back(x);

        int ans = 0;
        const int m = nums.size();

        for (int len = m % 2 ? m - 1 : m - 2; len >= 2; len -= 2)
            ans += g[len][len / 2][0];

        if (m % 2 != 0)
            return ans;

        int tot = 0, odd = 0;
        for (int len = m; len >= 1; len--) {
            int t = nums[len - 1];
            for (int num = (len == m) ? 1 : 0; num < t; num++) {
                int tk = (k - (tot + num * power) % k) % k;
                if (num % 2 == 0 && m / 2 >= odd)
                    ans += f[len - 1][m / 2 - odd][tk];
                else if (num % 2 == 1 && m / 2 >= odd + 1)
                    ans += f[len - 1][m / 2 - odd - 1][tk];
            }

            tot += t * power;
            odd += t % 2;
            power /= 10;
        }

        if (m % 2 == 0 && odd == m / 2 && tot % k == 0)
            ++ans;

        return ans;
    }

public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        init(k);

        return solve(high, k) - solve(low - 1, k);
    }
};
