/**
 * 2839. 判断通过操作能否让字符串相等 I
 * https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-i/description/
*/
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (!((s1[0] == s2[0] && s1[2] == s2[2]) || 
        (s1[0] == s2[2] && s1[2] == s2[0])))
            return false;

        return (s1[1] == s2[1] && s1[3] == s2[3]) || 
            (s1[1] == s2[3] && s1[3] == s2[1]);
    }
};
