/**
 * 241. 为运算表达式设计优先级
 * https://leetcode.cn/problems/different-ways-to-add-parentheses/
 */

class Solution {
public:
    vector<string> expr;

    // https://www.acwing.com/activity/content/code/content/445271/
    vector<int> diffWaysToCompute(string s) {
        for (int i = 0; i < s.size(); i ++ ) {
            if (isdigit(s[i])) {
                int j = i, x = 0;
                while (j < s.size() && isdigit(s[j])) x = x * 10 + (s[j ++ ] - '0');
                i = j - 1;
                expr.push_back(to_string(x));
            } else expr.push_back(s.substr(i, 1));
        }
        return dfs(0, expr.size() - 1);
    }

    vector<int> dfs(int l, int r) {
        if (l == r) return {stoi(expr[l])};
        vector<int> res;
        for (int i = l + 1; i < r; i += 2) {
            auto left = dfs(l, i - 1), right = dfs(i + 1, r);
            for (auto x: left)
                for (auto y: right) {
                    int z;
                    if (expr[i] == "+") z = x + y;
                    else if (expr[i] == "-") z = x - y;
                    else z = x * y;
                    res.push_back(z);
                }
        }
        return res;
    }
};

class Solution {
public:
    // https://www.acwing.com/solution/content/292/
    // 递归
    // 采用递归的方式，每次通过某个运算符，将当前字符串分成左右两部分，递归子问题计算。
    // 然后根据左右两部分返回的结果，通过该运算符组合成新的结果。
    // 递归出口为当前字符串仅有一个数字。
    vector<int> diffWaysToCompute(string ep) {
        return solve(0, ep.size() - 1, ep);
    }

    vector<int> solve(int l, int r, const string &s) {
        const int n = s.size();

        vector<int> ans;
        for (int i = l; i <= r; i++) {
            if (isdigit(s[i])) continue;

            for (int a : solve(l, i - 1, s))
                for (int b : solve(i + 1, r, s))
                    ans.push_back(s[i] == '+' ? a + b : (s[i] == '-' ? a - b : a * b));
        }

        return ans.empty() ? vector<int>{stoi(s.substr(l, r - l + 1))} : ans;
    }
};
