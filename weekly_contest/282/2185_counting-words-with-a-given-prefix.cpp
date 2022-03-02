class Solution {
public:
    bool is_pre(string word, string pref) {
        if(pref.size() > word.size()) return false;
        for(int i = 0; i < pref.size(); i++) {
            if(pref[i] != word[i]) return false;
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for(int i = 0; i < words.size(); i++) {
            if(is_pre(words[i], pref)) res++;
        }
        return res;
    }
};
