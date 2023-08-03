/**
 * 2730. 找到最长的半重复子字符串
 * https://leetcode.cn/problems/find-the-longest-semi-repetitive-substring/description/
*/

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans = 1, cnt = 0;

        for (int i = 1, j = 0; i < s.size(); i++) {
            if (s[i] == s[i - 1])
                ++cnt;

            while (cnt > 1 && j < i) {
                if (s[j] == s[j + 1])
                    --cnt;

                ++j;
            }

            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};
