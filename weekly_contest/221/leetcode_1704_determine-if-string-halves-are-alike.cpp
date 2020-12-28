/**
 * 5637. 判断字符串的两半是否相似
 * https://leetcode-cn.com/problems/determine-if-string-halves-are-alike/
 */

class Solution {
public:
    bool halvesAreAlike(string s) {
        int mid = s.size()/2;
        set<char> st {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int cnt = 0;
        for(int i = 0; i < mid; i++) {
            if(st.count(s[i]) != 0) {
                cnt++;
            }
            if(st.count(s[mid+i]) != 0) {
                cnt--;
            }
        }
        
        if(cnt == 0) {
            return true;
        } else {
            return false;
        }
    }
};
