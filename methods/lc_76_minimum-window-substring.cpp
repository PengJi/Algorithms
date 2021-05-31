/**
 * 76. 最小覆盖子串
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
 * 
 * https://leetcode-cn.com/problems/minimum-window-substring/
 */

class Solution {
public:
    // 滑动窗口
    // https://labuladong.github.io/ebook/%E7%AE%97%E6%B3%95%E6%80%9D%E7%BB%B4%E7%B3%BB%E5%88%97/%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%8A%80%E5%B7%A7.html
    // 时间复杂度：O(m*n)
    // 空间复杂度：O(n)
    string minWindow(string s, string t) {
        int len = s.size();
        if(len == 0) return "";

        int start = 0, minLen = INT_MAX;
        int left = 0, right = 0;
        unordered_map<char, int> window;
        unordered_map<char, int> needs;

        for(char c : t) needs[c]++;

        int match = 0;

        while(right < len) {
            char c1 = s[right];
            if(needs.count(c1)) {
                window[c1]++;
                if(window[c1] == needs[c1]) match++;
            }
            right++;

            while(match == needs.size()) {
                if(right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if(needs.count(c2)) {
                    window[c2]--;
                    if(window[c2] < needs[c2]) match--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
