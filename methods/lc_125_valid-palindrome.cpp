/**
 * 125. 验证回文串
 * https://leetcode-cn.com/problems/valid-palindrome/
 */

class Solution {
public:
    // 双指针
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    bool isPalindrome(string s) {
        int len = s.size();
        if(len <= 1) return true;

        int left = 0, right = len-1;
        while(left <= right) {
            while(left < len && !isalnum(s[left])) left++;
            while(right >= 0 && !isalnum(s[right])) right--;
            if(left <= right) {
                if(tolower(s[left]) == tolower(s[right])) {
                    left++;
                    right--;
                } else {
                    return false;
                }
            }
        }

        return true;        
    }

    bool check(char c) {
        return c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l < r) {
            while(l < r && !check(s[l])) l++;
            while(l < r && !check(s[r])) r--;
            if(s[l] != s[r] && s[l] != (s[r]^32)) return false;
            l++;
            r--;
        }

        return true;
    }
};
