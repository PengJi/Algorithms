/**
 * 93. 复原 IP 地址
 * https://leetcode.cn/problems/restore-ip-addresses/
 */

class Solution {
public:
    vector<string> ans;
    vector<int> path;

    // https://www.acwing.com/solution/content/175/
    vector<string> restoreIpAddresses(string s) {
        backtrack(0, 0, s);
        return ans;
    }

    // idx表示枚举到的字符串下标，cnt表示当前截断的IP个数，s表示原字符串
    void backtrack(int idx, int cnt, string &s) {
        if (idx == s.size()) {
            if (cnt == 4) {
                string ip = to_string(path[0]);
                for (int i = 1; i < 4; i++)
                    ip += '.' + to_string(path[i]);
                ans.push_back(ip);
            }
            return;
        }
        if (cnt > 4) return;

        unsigned t = 0;
        for (int i = idx; i < s.size(); i++) {
            t = t * 10 + s[i] - '0';
            if (t >= 0 && t < 256) {
                path.push_back(t);
                backtrack(i + 1, cnt + 1, s);
                path.pop_back();
            }
            if (!t) break;
        }
    }
};

class Solution {
public:
    vector<string> ans;
    vector<int> path;

    vector<string> restoreIpAddresses(string s) {
        dfs(0, 0, s);
        return ans;
    }

    // idx 表示枚举到的字符串下标，k表示当前截断的IP个数，s表示原字符串
    void dfs(int idx, int k, string &s) {
        if (idx == s.size()) {
            if (k == 4) {
                string ip = to_string(path[0]);
                for (int i = 1; i < 4; i++)
                    ip += '.' + to_string(path[i]);
                ans.push_back(ip);
            }
            return;
        }
        if (k > 4) return;  // 剪枝

        unsigned t = 0;
        for (int i = idx; i < s.size(); i++) {
            t = t * 10 + s[i] - '0';
            if (t >= 0 && t < 256) {
                path.push_back(t);
                dfs(i + 1, k + 1, s);
                path.pop_back();
            }

            if (!t) break;
        }
    }
};
