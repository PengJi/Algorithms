/**
 * 647. 回文子串
 * https://leetcode-cn.com/problems/palindromic-substrings/
 */

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {                                                             // 以某一个节点为中心遍历
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++) res++;          // 长度为奇数
            for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++) res++;  // 长度为偶数
        }

        return res;
    }
};
