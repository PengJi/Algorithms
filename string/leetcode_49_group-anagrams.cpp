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
        for(auto str:strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(str);
        }

        vector<vector<string>> res;
        for(auto item:mp){
            res.push_back(item.second);
        }

        return res;
    }
};
