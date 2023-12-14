/**
 * 2872. 可以被 K 整除连通块的最大数目
 * https://leetcode.cn/problems/maximum-number-of-k-divisible-components/description/
*/
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int ans = 0;
        function<long long(int, int)> dfs = [&](int x, int fa) -> long long {
            long long sum = values[x];
            for (int y : g[x])
                if (y != fa)
                    sum += dfs(y, x);
            ans += sum % k == 0;
            return sum;
        };
        dfs(0, -1);
        return ans;
    }
};
