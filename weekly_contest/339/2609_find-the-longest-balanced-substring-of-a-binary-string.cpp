/**
 * 2609. 最长平衡子字符串
 * https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string/description/
*/
class Solution {
public:
    // 思维题
    int findTheLongestBalancedSubstring(string s) {
        const int n = s.size();
        int ans = 0, zero = 0, one = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                one++;

                continue;
            }

            if (i > 0 && s[i - 1] == '1') {
                ans = max(ans, 2 * min(zero, one));
                one = 0;
                zero = 0;
            }

            zero++;
        }

        return max(ans, 2 * min(one, zero));
    }
};
