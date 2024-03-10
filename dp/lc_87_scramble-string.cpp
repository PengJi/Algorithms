/**
 * 87. 扰乱字符串
 * https://leetcode-cn.com/problems/scramble-string/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/170/
    // 时间复杂度：O(5^n)
    // 空间复杂度：O(1)
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        string ss1 = s1, ss2 = s2;
        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        if (ss1 != ss2) return false;

        int len1 = s1.size(), len2 = s2.size();
        for (int i = 1; i < len1; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(len2 - i)) && isScramble(s1.substr(i), s2.substr(0, len2 - i)))
                return true;
        }

        return false;
    }
};

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> f(n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        for (int k = 1; k <= n; k++)
            for (int i = 0; i + k - 1 < n; i++)
                for (int j = 0; j + k - 1 < n; j++) {
                    if (k == 1) {
                        if (s1[i] == s2[j]) f[i][j][k] = true;
                    } else {
                        for (int u = 1; u < k; u++) {
                            if (f[i][j][u] && f[i + u][j + u][k - u] || f[i][j + k - u][u] && f[i + u][j][k - u]) {
                                f[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
        return f[0][0][n];
    }
};
