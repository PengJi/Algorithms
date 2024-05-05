/**
 * 5. 最长回文子串
 * https://leetcode-cn.com/problems/longest-palindromic-substring/
 */

class Solution {
public:
    // 动态规划
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(n^2)
    string longestPalindrome(string s) {
        int len = s.size();
        if (len <= 1) return s;

        int maxLen = 1;
        string ans = s.substr(0, 1);
        vector<vector<bool>> dp(len, vector<bool>(len, false));

        for (int i = len - 1; i >= 0; i--) {  // 行倒序遍历
            for (int j = i; j < len; j++) {   // 列从左到右，遍历右半部分
                // 状态转移方程，两边字符是否相等
                dp[i][j] = s[i] == s[j] && (i + 1 > j - 1 || dp[i + 1][j - 1]);

                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    ans = s.substr(i, maxLen);
                }
            }
        }

        return ans;
    }
};


class Solution {
public:
    // 暴力解法
    // 以当前节点为中心，左右两边遍历
    // O(n^2)/O(1)
    string longestPalindrome(string s) {
        int maxLen = 0;
        string res;
        int len = s.size();

        for(int i = 0; i < s.size(); i++) {
            int step = 0;
            // 长度为奇数
            while(i-step >=0 && i+step <len && s[i-step] == s[i+step]) step++;
            step--;
            if(step*2+1 > maxLen) {
                maxLen = step*2+1;
                res = s.substr(i-step, maxLen);
            }

            // 长度为偶数
            step = 0;
            int left = i, right = i+1;
            while(left-step >= 0 && right+step < len && s[left-step] == s[right+step]) step++;
            step--;
            if((step+1)*2 > maxLen) {
                maxLen = (step+1)*2;
                res = s.substr(left-step, maxLen);
            }
        }

        return res;
    }
};
