/**
 * 1784. 检查二进制字符串字段
 * https://leetcode-cn.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
 */

class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.size() == 1)  return true;
        for(int i = 1; i <= s.size()-1; i++) {
            if(s[i-1] == '0' && s[i] == '1') return false;
        }
        
        return true;
    }
};
