/**
 * 5714. 替换字符串中的括号内容
 * https://leetcode-cn.com/problems/evaluate-the-bracket-pairs-of-a-string/
 */

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(int i = 0; i < knowledge.size(); i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        
        int idx = 0;
        string res = "";
        while(idx < s.size()) {
            int c = 0;
            if(s[idx] == '(') {
                int pos = idx+1;
                while(s[idx] != ')') {
                    idx++;
                    c++;
                }
                string ss = s.substr(pos, c-1);
                if(mp.count(ss) != 0) res += mp[ss];
                else res += '?';
                idx++;
            } else {
                int pos = idx;
                while(s[idx] != '(' && idx < s.size()) {
                    idx++;
                    c++;
                }
                res += s.substr(pos, c);
            }
        }
        
        return res;
    }
};
