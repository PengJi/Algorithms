/**
 * 5781. 删除一个字符串中所有出现的给定子字符串
 * https://leetcode-cn.com/problems/remove-all-occurrences-of-a-substring/
 */

class Solution {
public:
    string removeOccurrences(string s, string p) {
        while(true) {
            int k = s.find(p);
            if(k == -1) break;
            s = s.substr(0, k) + s.substr(k + p.size());
        }

        return s;
    }
};
