/**
 * 76. 最小覆盖子串
 * https://leetcode-cn.com/problems/minimum-window-substring/
 */

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;  // hs 表示窗口内各字符的个数，ht 表示目标字符串中各字符的个数
        for (auto& c : t) ht[c]++;

        string res;
        int cnt = 0;                                 // 窗口内有效字符的个数
        for (int i = 0, j = 0; i < s.size(); i++) {  // j 为滑动窗口的左边界，i 为右边界
            hs[s[i]]++;                              // 窗口内对应字符的个数

            if (hs[s[i]] <= ht[s[i]]) cnt++;  // 窗口内有效字符的个数

            while (hs[s[j]] > ht[s[j]]) hs[s[j++]]--;  // 缩小滑动窗口的大小，j++

            if (cnt == t.size()) {  // 有效字符个数等于目标字符串的字符个数
                if (res.empty() || (i - j + 1) < res.size()) {
                    res = s.substr(j, i - j + 1);
                }
            }
        }

        return res;
    }
};
