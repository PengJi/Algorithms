/**
 * 301. 删除无效的括号
 * https://leetcode-cn.com/problems/remove-invalid-parentheses/
 */

class Solution {
public:
    vector<string> ans;

    // https://www.acwing.com/activity/content/code/content/470996/
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (auto x : s)
            if (x == '(')
                l++;
            else if (x == ')') {
                if (l == 0)
                    r++;
                else
                    l--;
            }

        dfs(s, 0, "", 0, l, r);
        return ans;
    }

    void dfs(string& s, int u, string path, int cnt, int l, int r) {
        if (u == s.size()) {
            if (!cnt) ans.push_back(path);
            return;
        }

        if (s[u] != '(' && s[u] != ')')
            dfs(s, u + 1, path + s[u], cnt, l, r);
        else if (s[u] == '(') {
            int k = u;
            while (k < s.size() && s[k] == '(') k++;
            l -= k - u;
            for (int i = k - u; i >= 0; i--) {
                if (l >= 0) dfs(s, k, path, cnt, l, r);
                path += '(';
                cnt++, l++;
            }
        } else if (s[u] == ')') {
            int k = u;
            while (k < s.size() && s[k] == ')') k++;
            r -= k - u;
            for (int i = k - u; i >= 0; i--) {
                if (cnt >= 0 && r >= 0) dfs(s, k, path, cnt, l, r);
                path += ')';
                cnt--, r++;
            }
        }
    }
};
