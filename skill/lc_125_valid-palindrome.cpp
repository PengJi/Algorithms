/**
 * 125. 验证回文串
 * https://leetcode-cn.com/problems/valid-palindrome/
 */

class Solution {
public:
    // 双指针
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !check(s[l])) l++;
            while (l < r && !check(s[r])) r--;
            if (s[l] != s[r] && s[l] != (s[r] ^ 32)) return false;
            l++;
            r--;
        }

        return true;
    }

    bool check(char c) {
        return c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
};
