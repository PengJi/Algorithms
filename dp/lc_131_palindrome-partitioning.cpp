/**
 * 131. 分割回文串
 * https://leetcode-cn.com/problems/palindrome-partitioning/
 */

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    // https://www.acwing.com/solution/content/226/
    vector<vector<string>> partition(string s) {
        dfs("", 0, s);
        return ans;
    }

    bool check(string &now)
    {
        if (now.empty()) return false;
        for (int i = 0, j = now.size() - 1; i < j; i ++, j -- )
            if (now[i] != now[j])
                return false;
        return true;
    }

    void dfs(string now, int u, string &s)
    {
        if (u == s.size())
        {
            if (check(now))
            {
                path.push_back(now);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }

        if (check(now))
        {
            path.push_back(now);
            dfs("", u, s);
            path.pop_back();
        }

        dfs(now + s[u], u + 1, s);
    }
};
