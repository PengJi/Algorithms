/**
 * 205. 同构字符串
 * https://leetcode-cn.com/problems/isomorphic-strings/
 */

class Solution {
public:
    // 对比两个字符串对应位置的字符在字符串内第一次出现的位置。
    // https://leetcode-cn.com/problems/isomorphic-strings/solution/cxiang-xi-ti-jie-shuang-jie-by-youlookdeliciousc/
    bool isIsomorphic(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            if (s.find(s[i]) != t.find(t[i]))
                return false;
        }

        return true;
    }
};

class Solution {
public:
    // 两个哈希表存储映关系
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> st, ts;

        for (int i = 0; i < s.size(); i++) {
            if (st.count(s[i])) {
                if (st[s[i]] != t[i]) return false;
            } else {
                st[s[i]] = t[i];
            }

            if (ts.count(t[i])) {
                if (ts[t[i]] != s[i]) return false;
            } else {
                ts[t[i]] = s[i];
            }
        }

        return true;
    }
};
