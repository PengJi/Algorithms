/**
 * 290. 单词规律
 * https://leetcode-cn.com/problems/word-pattern/
 */

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word) words.push_back(word);
        if(words.size() != pattern.size()) return false;
        unordered_map<char, string> ps;
        unordered_map<string, char> sp;
        for(int i = 0; i < pattern.size(); i++) {
            char a = pattern[i];
            string b = words[i];
            if(ps.count(a) && ps[a] != b) return false;
            ps[a] = b;
            if(sp.count(b) && sp[b] != a) return false;
            sp[b] = a;
        }

        return true;
    }
};
