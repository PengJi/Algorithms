/**
 * 1684. 统计一致字符串的数目
 * https://leetcode-cn.com/problems/count-the-number-of-consistent-strings/
 */

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> b(26);
        for(char c : allowed) {
            b[c - 'a'] = 1;
        }
        int res = 0;
        for(string s : words) {
            int ok = 1;
            for(char c : s) {
                ok &= b[c - 'a'];
            }
            res += ok;
        }
        return res;
    }
};
