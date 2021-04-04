/**
 * 1816. 截断句子
 * https://leetcode-cn.com/problems/truncate-sentence/
 */

class Solution {
public:
    string truncateSentence(string s, int k) {
        int cnt = 0, cnt_zero = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') cnt_zero++;
            if(cnt_zero == k) break;
            cnt++;
        }
        
        return s.substr(0, cnt);
    }
};