/**
 * 87. 扰乱字符串
 * https://leetcode-cn.com/problems/scramble-string/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/170/
    // 时间复杂度：O(5^n)
    // 空间复杂度：O(1)
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        string ss1 = s1, ss2 = s2;
        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        if(ss1 != ss2) return false;

        int len1 = s1.size(), len2 = s2.size();
        for(int i = 1; i < len1; i++) {
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0, i), s2.substr(len2-i)) && isScramble(s1.substr(i), s2.substr(0, len2-i)))
                return true;
        }

        return false;
    }
};
