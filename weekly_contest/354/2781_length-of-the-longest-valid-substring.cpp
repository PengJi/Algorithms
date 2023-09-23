/**
 * 2781. 最长合法子字符串的长度
 * https://leetcode.cn/problems/length-of-the-longest-valid-substring/description/
*/
class Solution {
public:
    // 哈希表、双指针
    int longestValidSubstring(string word, vector<string>& forbidden) {
        const int n = word.size();
        unordered_set<string> v(forbidden.begin(), forbidden.end());

        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            for (int k = i; k >= max(j, i - 9); k--)
                if (v.find(word.substr(k, i - k + 1)) != v.end()) {
                    j = k + 1;

                    break;
                }

            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};
