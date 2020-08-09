/**
 * 5483. 整理字符串
 * https://leetcode-cn.com/problems/make-the-string-great/
 */

class Solution {
public:
    string makeGood(string s) {
        string stk;
        int n;
        for(int i = 0; i < s.size(); i++) {
            stk += s[i];
            n = stk.size();

            if(n >= 2 && (stk[n-1] + 32 == stk[n-2] || stk[n-1] - 32 == stk[n-2])) {
                stk.resize(n-2);
            }
        }

        return stk;
    }
};
