/**
 * 125. 验证回文串
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
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
