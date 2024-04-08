/**
 * 647. 回文子串
 * https://leetcode-cn.com/problems/palindromic-substrings/
 */

class Solution {
public:
    // 中心扩展
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            // 奇数长度
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++) {
                res++;
            }
            // 偶数长度
            for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++) {
                res++;
            }
        }

        return res;
    }
};

// Manacher 算法
