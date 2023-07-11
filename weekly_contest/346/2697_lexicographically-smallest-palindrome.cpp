/**
 * 2697. 字典序最小回文串
 * https://leetcode.cn/problems/lexicographically-smallest-palindrome
*/

class Solution {
public:
    // 双指针
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        for(int i = 0, j = n-1; i < j; i++, j--) {
            if(s[i]< s[j]) s[j] = s[i];
            else s[i] = s[j];
        }

        return s;
    }
};
