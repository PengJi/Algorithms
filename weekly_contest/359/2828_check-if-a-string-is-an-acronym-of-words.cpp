/**
 * 2828. 判别首字母缩略词
 * https://leetcode.cn/problems/check-if-a-string-is-an-acronym-of-words/description/
*/
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (words.size() != s.size())
            return false;

        for (int i = 0; i < s.size(); i++)
            if (words[i][0] != s[i])
                return false;

        return true;
    }
};
