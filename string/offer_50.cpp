/**
 * 剑指 Offer 50. 第一个只出现一次的字符
 * https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
 */

class Solution {
public:
    // 哈希表
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    char firstUniqChar(string s) {
        unordered_map<char, bool> mp;
        for(char c : s) {
            mp[c] = mp.find(c) == mp.end();
        }

        for(char c : s) {
            if(mp[c]) return c;
        }

        return ' ';
    }
};
