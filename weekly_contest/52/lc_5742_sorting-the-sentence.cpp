/**
 * 5742. 将句子排序
 * https://leetcode-cn.com/problems/sorting-the-sentence/
 */

class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int, string>> vec;
        for(int i = 0; i < s.size(); i++) {
            string word;
            int j = i;
            while(j < s.size() && s[j] != ' ') word += s[j++];
            i = j;
            vec.push_back({word.back()-'1', word.substr(0, word.size()-1)});
        }

        sort(vec.begin(), vec.end());
        string res;
        for(auto w : vec) {
            res += w.second + ' ';
        }
        res.pop_back();

        return res;
    }
};
