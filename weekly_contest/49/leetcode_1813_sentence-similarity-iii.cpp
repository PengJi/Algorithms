/**
 * 1813. 句子相似性 III
 * https://leetcode-cn.com/problems/sentence-similarity-iii/
 */

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.size() > sentence2.size()) return areSentencesSimilar(sentence2, sentence1);
        vector<string> s1, s2;
        stringstream ss1(sentence1), ss2(sentence2);
        string s;
        while(ss1 >> s) s1.push_back(s);
        while(ss2 >> s) s2.push_back(s);
        int i=0, j=s1.size()-1;
        for(int k = 0; k < s2.size(), i < s1.size(); k++) {
            if(s2[k] == s1[i]) i++;
            else break;
        }
        for(int k = s2.size()-1; k >= 0, j >= 0; k--) {
            if(s2[k] == s1[j]) j--;
            else break;
        }
        return i > j;
    }
};
