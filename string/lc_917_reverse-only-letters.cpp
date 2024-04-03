/**
 * 917. 仅仅反转字母
 * https://leetcode-cn.com/problems/reverse-only-letters/
 */

class Solution {
public:
    // 双指针
    string reverseOnlyLetters(string s) {
        string res = s;
        int l = 0, r = res.size() - 1;
        while (l < r) {
            if (!isalpha(res[l])) l++;
            if (!isalpha(res[r])) r--;
            if (isalpha(res[l]) && isalpha(res[r]))
                swap(res[l++], res[r--]);
        }

        return res;
    }
};

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int len = s.size();
        int l = 0, r = len - 1;

        while (l < r) {
            while (l < len && !isalpha(s[l])) l++;
            while (r >= 0 && !isalpha(s[r])) r--;

            if (l < r && isalpha(s[l]) && isalpha(s[r])) {
                swap(s[l], s[r]);
            }
            l++;
            r--;
        }

        return s;
    }
};
