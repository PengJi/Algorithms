/**
 * 5784. 重新分配字符使所有字符串都相等
 * https://leetcode-cn.com/problems/redistribute-characters-to-make-all-strings-equal/
 */

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> mp;
        for(auto s: words) {
            for(auto x: s) {
                mp[x]++;
            }
        }

        for(auto [a, b] : mp) {
            if(b % words.size() != 0) return false;
        }

        return true;
    }
};
