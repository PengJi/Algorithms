/**
 * 557. 反转字符串中的单词 III
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
 */

class Solution {
public:
    string reverseWords(string s) {
        int j;  // 右边界
        for (int i = 0; i < s.size(); i++) {
            j = i;
            while (j < s.size() && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }

        return s;
    }
};
