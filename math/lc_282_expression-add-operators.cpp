/**
 * 282. 给表达式添加运算符
 * https://leetcode-cn.com/problems/expression-add-operators/
 */

typedef long long LL;

class Solution {
public:
    vector<string> ans;
    string path;

    // https://www.acwing.com/solution/content/332/
    vector<string> addOperators(string num, int target) {
        path.resize(100);
        dfs(num, 0, 0, 0, 1, target);
        return ans;
    }

    void dfs(string& num, int u, int len, LL a, LL b, LL target) {
        if (u == num.size()) {
            if (a == target) ans.push_back(path.substr(0, len - 1));
        } else {
            LL c = 0;
            for (int i = u; i < num.size(); i ++ ) {
                c = c * 10 + num[i] - '0';
                path[len ++ ] = num[i];

                // +
                path[len] = '+';
                dfs(num, i + 1, len + 1, a + b * c, 1, target);

                if (i + 1 < num.size()) {
                    // -
                    path[len] = '-';
                    dfs(num, i + 1, len + 1, a + b * c, -1, target);

                    // *
                    path[len] = '*';
                    dfs(num, i + 1, len + 1, a, b * c, target);
                }
                if (num[u] == '0') break;
            }
        }
    }
};
