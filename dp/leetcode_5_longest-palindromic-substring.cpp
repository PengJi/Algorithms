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
        if(len <= 1) return s;

        int maxLen = 1;
        string ans = s.substr(0, 1);
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for(int i = len-1; i >= 0; i--) {  // 行倒序遍历
            for(int j = i; j < len; j++) {  // 列从左到有，遍历右半部分
                // 两边字符是否相等
                dp[i][j] = s[i] == s[j] && (i+1 > j-1 || dp[i+1][j-1]);
                if(dp[i][j] && j-i+1 > maxLen) {
                    maxLen = j-i+1;
                    ans = s.substr(i, maxLen);
                }
            }
        }

        return ans;
    } 


    // 动态规划
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(n^2)
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;

        int start = 0,maxLen = 1, n = s.size();
        bool isPal[1000][1000] = {false};

        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if((i+1>j-1 || isPal[i+1][j-1]) && s[i]==s[j]){
                    isPal[i][j] = true;
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        start=i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
