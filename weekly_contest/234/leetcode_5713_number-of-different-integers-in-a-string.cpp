/**
 * 5713. 字符串中不同整数的数目
 * https://leetcode-cn.com/problems/number-of-different-integers-in-a-string/
 */

class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> st;
        int idx = 0;
        while(idx < word.size()) {
            if(word[idx] >= '0' && word[idx] <= '9') {
                int s = 1;
                while(s <= word.size() && word[idx] >= '0' && word[idx] <= '9') {
                    idx++;
                    s++;
                }
                string tmp = word.substr(idx-s+1, s-1);
                int b = 0;
                while(tmp[b] == '0') {
                    b++;
                }
                st.insert(tmp.substr(b));
            } else {
                idx++;
            } 
        }
        
        return st.size();
    }
};
