/**
 * 2734. 执行子串操作后的字典序最小字符串
 * https://leetcode.cn/problems/lexicographically-smallest-string-after-substring-operation/description/
*/

class Solution {
public:
    // 贪心
    string smallestString(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] > 'a') {
                for (; i < n && s[i] > 'a'; i++)
                    s[i]--;
                return s;
            }
        }
        s.back() = 'z';
        return s;
    }
};
