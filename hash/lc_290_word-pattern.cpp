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
        while (ss >> word)
            words.push_back(word);
        if (words.size() != pattern.size())
            return false;
        unordered_map<char, string> ps;
        unordered_map<string, char> sp;
        for (int i = 0; i < pattern.size(); i++) {
            char a = pattern[i];
            string b = words[i];
            if (ps.count(a) && ps[a] != b)
                return false;
            ps[a] = b;
            if (sp.count(b) && sp[b] != a)
                return false;
            sp[b] = a;
        }

        return true;
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word)
            words.push_back(word);
        if (pattern.size() != words.size())
            return false;
        unordered_map<string, char> sp;  // word 到 pattern 的映射
        unordered_map<char, string> ps;  // pattern 到 word  的映射
        for (int i = 0; i < words.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (ps.count(c) && ps[c] != w)
                return false;
            ps[c] = w;
            if (sp.count(w) && sp[w] != c)
                return false;
            sp[w] = c;
        }

        return true;
    }
};
