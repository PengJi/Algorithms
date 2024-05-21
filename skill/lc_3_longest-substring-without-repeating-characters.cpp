/**
 * 3. 无重复字符的最长子串
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 */

class Solution {
public:
    // 滑动窗口
    // O(n)/O(n)
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char> st;
        int left = 0;

        for (int i = 0; i < s.size(); i++) {
            while (st.count(s[i]) != 0) {
                st.erase(s[left]);
                left++;
            }
            res = max(res, i - left + 1);
            st.insert(s[i]);
        }

        return res;
    }
};
