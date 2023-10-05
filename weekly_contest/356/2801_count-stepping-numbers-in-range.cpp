/**
 * 2801. 统计范围内的步进数字数目
 * https://leetcode.cn/problems/count-stepping-numbers-in-range/description/
*/
const int N = 110;
const int mod = 1000000007;

class Solution {
private:
    int f[N][10];

    void init(int n) {
        memset(f, 0, sizeof(f));

        for (int j = 0; j < 10; j++)
            f[1][j] = 1;

        for (int i = 2; i <= n; i++)
            for (int j = 0; j < 10; j++) {
                if (j > 0) f[i][j] = (f[i][j] + f[i - 1][j - 1]) % mod;
                if (j < 9) f[i][j] = (f[i][j] + f[i - 1][j + 1]) % mod;
            }
    }

    int solve(const string &s) {
        const int n = s.size();

        int res = 0;

        for (int i = 1; i < n; i++)
            for (int j = 1; j < 10; j++)
                res = (res + f[i][j]) % mod;

        for (int j = 1; j < s[n - 1] - '0'; j++)
            res = (res + f[n][j]) % mod;

        for (int i = n - 2; i >= 0; i--) {
            int prev = s[i + 1] - '0';
            int cur = s[i] - '0';

            if (prev > 0 && cur >= prev)
                res = (res + f[i + 1][prev - 1]) % mod;

            if (cur >= prev + 2)
                res = (res + f[i + 1][prev + 1]) % mod;

            if (abs(cur - prev) != 1)
                break;
        }

        return res + check(s);
    }

    int check(const string &s) {
        for (int i = 1; i < s.size(); i++)
            if (abs(s[i] - s[i - 1]) != 1)
                return 0;

        return 1;
    }

public:
    int countSteppingNumbers(string low, string high) {
        init(high.size());

        reverse(low.begin(), low.end());
        reverse(high.begin(), high.end());

        return ((solve(high) - solve(low) + check(low)) % mod + mod) % mod;
    }
};
