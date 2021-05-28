/**
 * 680. 验证回文字符串 Ⅱ
 * https://leetcode-cn.com/problems/valid-palindrome-ii/
 */

class Solution {
public:
    // 双指针，一个从前往后，一个从后往前，依次遍历，
    // 遇到不同时，由于只删除一个字符，要么删除左边，要么删除右边
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    bool validPalindrome(string s) {
        int len = s.size();
        for(int i = 0, j = len -1; i < j; i++, j--) {
            if(s[i] != s[j]) return (judge(s, i+1, j) || judge(s, i, j-1));
        }

        return true;
    }

    bool judge(string s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }

        return true;
    }
};
