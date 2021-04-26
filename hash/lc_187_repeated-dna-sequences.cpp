/**
 * 187. 重复的DNA序列
 * https://leetcode-cn.com/problems/repeated-dna-sequences/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/309/
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> mp;
        string tmp;
        for(int i = 0; i + 10 <= s.size(); i++) {
            tmp = s.substr(i, 10);
            if(mp[tmp] == 1) res.push_back(tmp);
            mp[tmp]++;
        }

        return res;
    }
};
