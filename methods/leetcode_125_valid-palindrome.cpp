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
            while(left < len && !isalnum(s[left])) {
                left++;
            }

            while(right >= 0 && !isalnum(s[right])) {
                right--;
            }

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
};