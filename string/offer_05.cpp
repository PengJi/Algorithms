/**
 * 剑指 Offer 05. 替换空格
 * https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
 */

class Solution {
public:
    string replaceSpace(string s) {
        string ans;

        for(char c : s) {
            if(c == ' ') {
                ans += "%20";
            } else {
                ans += c;
            }
        }

        return ans;
    }
};
