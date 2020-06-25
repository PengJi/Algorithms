/**
 * 139. 单词拆分
 * https://leetcode-cn.com/problems/word-break/
 */

class Solution {
public:
    // 动态规划
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(n)
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto item: wordDict) {
            dict.insert(item);
        }

        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};