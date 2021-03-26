/**
 * 97. 交错字符串
 * https://leetcode-cn.com/problems/interleaving-string/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/179/
    // O(n^2)
    // O(1)
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size();
        if((len1 + len2) != s3.size()) return false;

        vector<vector<bool>> dp(len1+1, vector<bool>(len2+1));
        s1 = ' ' + s1;
        s2 = ' ' + s2;
        s3 = ' ' + s3;
        for(int i = 0; i <= len1; i++) {
            for(int j = 0; j <= len2; j++) {
                if(!i && !j) dp[i][j] = true;
                else {
                    if(i && s1[i] == s3[i+j]) dp[i][j] = dp[i-1][j];
                    if(j && s2[j] == s3[i+j]) dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }
        }

        return dp[len1][len2];
    }
};
