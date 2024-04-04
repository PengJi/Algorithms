/**
 * 709. 转换成小写字母
 * https://leetcode-cn.com/problems/to-lower-case/
 */

class Solution {
public:
    string toLowerCase(string s) {
        for (auto& c : s) {
            if (c >= 65 && c <= 90) c |= 32;
        }

        return s;
    }
};