/**
 * 541. 反转字符串 II
 * https://leetcode-cn.com/problems/reverse-string-ii/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/reverse-string-ii/solution/cjian-ji-dai-ma-xiang-xi-zhu-shi-bu-kan-hou-hui-xi/
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) { 
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
                continue;
            } 
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            reverse(s.begin() + i, s.begin() + s.size());                     
        }
        return s;
    }
};