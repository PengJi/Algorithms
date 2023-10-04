/**
 * 2800. 包含三个字符串的最短字符串
 * https://leetcode.cn/problems/shortest-string-that-contains-three-strings/description/
*/
class Solution {
private:
    void append(string &s, const string &t) {
        if (s.find(t) != s.npos)
            return;

        const int n = s.size(), m = t.size();

        for (int st = max(0, n - m + 1); st < n; st++) {
            bool flag = true;

            for (int i = st, j = 0; i < n; i++, j++)
                if (s[i] != t[j]) {
                    flag = false;

                    break;
                }

            if (flag) {
                for (int j = n - st; j < m; j++)
                    s += t[j];

                return;
            }
        }

        s += t;
    }

    string solve(const string &a, const string &b, const string &c) {
        string s = a;

        append(s, b);
        append(s, c);

        return s;
    }

public:
    string minimumString(string a, string b, string c) {
        vector<string> res;

        res.push_back(solve(a, b, c));
        res.push_back(solve(a, c, b));
        res.push_back(solve(b, a, c));
        res.push_back(solve(b, c, a));
        res.push_back(solve(c, a, b));
        res.push_back(solve(c, b, a));

        string ans = res[0];

        for (int i = 1; i < 6; i++) {
            if (ans.size() > res[i].size() ||
            (ans.size() == res[i].size() && ans > res[i]))
                ans = res[i];
        }

        return ans;
    }
};
