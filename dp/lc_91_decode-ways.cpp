/**
 * 91. 解码方法
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 *
 * https://leetcode-cn.com/problems/decode-ways/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/decode-ways/solution/c-wo-ren-wei-hen-jian-dan-zhi-guan-de-jie-fa-by-pr/
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        int pre = 1, curr = 1;  // dp[-1] = dp[0] = 1
        int tmp;
        for (int i = 1; i < s.size(); i++) {
            tmp = curr;
            if (s[i] == '0')
                if (s[i - 1] == '1' || s[i - 1] == '2')
                    curr = pre;
                else
                    return 0;
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
                curr = curr + pre;

            pre = tmp;
        }

        return curr;
    }

    // 动态规划
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int numDecodings(string s) {
        int dp2 = 1;
        int dp1 = s.back() == '0' ? 0 : 1;
        int dp = dp1;

        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] == '0') {
                dp = 0;
            } else {
                dp = dp1;
                if (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6') {
                    dp += dp2;
                }
            }
            dp2 = dp1;
            dp1 = dp;
        }

        return dp;
    }
};
