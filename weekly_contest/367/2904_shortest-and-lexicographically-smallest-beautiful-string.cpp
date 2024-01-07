/**
 * 2904. 最短且字典序最小的美丽子字符串
 * https://leetcode.cn/problems/shortest-and-lexicographically-smallest-beautiful-string/description/
*/
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if (count(s.begin(), s.end(), '1') < k) {
            return "";
        }
        for (int size = k;; size++) {
            string ans = "";
            for (int i = size; i <= s.length(); i++) {
                string t = s.substr(i - size, size);
                if ((ans == "" || t < ans) && count(t.begin(), t.end(), '1') == k) {
                    ans = t;
                }
            }
            if (!ans.empty()) {
                return ans;
            }
        }
    }
};
