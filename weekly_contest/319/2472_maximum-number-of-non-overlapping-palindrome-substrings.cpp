/**
 * 2472. 不重叠回文子字符串的最大数目
 * https://leetcode.cn/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/
*/
const int N = 2010;

class Solution {
private:
    bool v[N][N];
    int f[N];

public:
    // 动态规划
    int maxPalindromes(string s, int k) {
        const int n = s.size();

        for (int i = n; i >= 1; i--) {
            v[i][i] = v[i][i - 1] = true;
            for (int j = i + 1; j <= n; j++)
                v[i][j] = s[i - 1] == s[j - 1] ? v[i + 1][j - 1] : false;
        }

        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1];
            for (int j = i - k; j >= 0; j--)
                if (v[j + 1][i])
                    f[i] = max(f[i], f[j] + 1);
        }

        return f[n];
    }
};
