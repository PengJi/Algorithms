/**
 * 58. 最后一个单词的长度
 * https://leetcode-cn.com/problems/length-of-last-word/
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') continue;
            int j = i - 1;
            while (j >= 0 && s[j] != ' ') j--;
            return i - j;
        }

        return 0;
    }
};
