/**
 * 131. 分割回文串
 * https://leetcode-cn.com/problems/palindrome-partitioning/
 */

class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<string>> res;

    // https://www.acwing.com/solution/content/3872/
    vector<vector<string>> partition(string s) {
        int n = s.length();
        dp = vector<vector<int>> (n,vector<int>(n,0));
        dp[0][0] = 1;
        for(int i = 1 ; i < n ; i ++) 
            dp[i][i] = 1,dp[i - 1][i] = (s[i - 1] == s[i]);
        for(int len = 2; len < n ; len ++)
        {
            for(int i = 0 ; i + len < n ; i ++)
            {
                int j = i +len;
                dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1] == 1);
            }
        }
        vector<string> path;
        dfs(s,0,n,path);
        return res;
    }
    void dfs(string &s,int u,int n,vector<string> &path)
    {
        if(u == n){res.push_back(path);return;}
        for(int i = u ; i < n ; i ++)
        {
            if(dp[u][i] == 1)
            {
                path.push_back(s.substr(u,i - u + 1));
                dfs(s,i + 1,n,path);
                path.pop_back();
            }
        }
    }
};
