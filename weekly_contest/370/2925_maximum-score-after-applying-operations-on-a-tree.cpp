/**
 * 2925. 在树上执行操作以后得到的最大分数
 * https://leetcode.cn/problems/maximum-score-after-applying-operations-on-a-tree/description/
*/
#define LL long long

class Solution {
private:
    vector<vector<int>> graph;
    vector<LL> f, g;

    void solve(int u, int fa, const vector<int> &values) {
        g[u] = values[u];
        f[u] = 0;

        bool isleaf = true;
        for (int v : graph[u]) {
            if (v == fa)
                continue;

            solve(v, u, values);
            g[u] += g[v];
            f[u] += f[v];
            isleaf = false;
        }

        if (!isleaf)
            f[u] = max(f[u] + values[u], g[u] - values[u]);
    }

public:
    LL maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        const int n = values.size();
        graph.resize(n);

        for (const auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        f.resize(n);
        g.resize(n);

        solve(0, -1, values);

        return f[0];
    }
};
