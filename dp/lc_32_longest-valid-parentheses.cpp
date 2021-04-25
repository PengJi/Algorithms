/**
 * 32. 最长有效括号
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * https://leetcode-cn.com/problems/longest-valid-parentheses/
 */

class Solution {
public:
    // 遍历
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int longestValidParentheses(string s) {
        int len = s.size();
        if(len == 0) return 0;

        int left = 0, right = 0, maxlength = 0;

        // 从左向右寻找最长
        for(int i = 0; i < len; i++) {
            if(s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if(left == right) {
                maxlength = max(maxlength, right * 2);
            } else if(left < right) {
                left = right = 0;
            }
        }

        left = right = 0;

        // 从右向左寻找最长
        for(int i = len-1; i >= 0; i--) {
            if(s[i] == ')') {
                right++;
            } else {
                left++;
            }

            if(left == right) {
                maxlength = max(maxlength, left * 2);
            } else if(left > right) {
                left = right = 0;
            }
        }

        return maxlength;
    }

    // 动态规划
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int longestValidParentheses(string s) {
        int size = s.length();
        vector<int> dp(size, 0);

        int maxVal = 0;
        for(int i = 1; i < size; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2;
                    if (i - 2 >= 0) {
                        dp[i] = dp[i] + dp[i - 2];
                    }
                } else if (dp[i - 1] > 0) {
                    if ((i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if ((i - dp[i - 1] - 2) >= 0) {
                            dp[i] = dp[i] + dp[i - dp[i - 1] - 2];
                        }
                    }
                }
            }
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
};
