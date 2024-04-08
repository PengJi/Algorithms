/**
 * 49. 字母异位词分组
 * 给定一个字符串数组，将字母异位词组合在一起。
 * 字母异位词指字母相同，但排列不同的字符串。
 * 
 * https://leetcode-cn.com/problems/group-anagrams/
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto s : strs) {
            string ss = s;
            sort(ss.begin(), ss.end());
            mp[ss].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& item : mp) res.push_back(item.second);
        return res;
    }
};
