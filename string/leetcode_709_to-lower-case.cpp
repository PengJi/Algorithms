/**
 * 709. 转换成小写字母
 * https://leetcode-cn.com/problems/to-lower-case/
 */

class Solution {
public:
    string toLowerCase(string str) {
        for(auto& s:str)
            s |= 32;
        return str;
    }
};
