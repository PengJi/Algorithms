/**
 * 205. 同构字符串
 * https://leetcode-cn.com/problems/isomorphic-strings/
 */

class Solution {
public:
    // 对比两个字符串对应位置的字符在字符串内第一次出现的位置。
    // https://leetcode-cn.com/problems/isomorphic-strings/solution/cxiang-xi-ti-jie-shuang-jie-by-youlookdeliciousc/
    bool isIsomorphic(string s, string t) {
        for(int i=0; i<s.size(); i++){
            if(s.find(s[i]) != t.find(t[i]))
                return false;
        }

        return true;
    }
};
