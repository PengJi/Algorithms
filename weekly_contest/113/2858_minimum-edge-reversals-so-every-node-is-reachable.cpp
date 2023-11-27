/**
 * 2858. 可以到达每一个节点的最少边反转次数
 * https://leetcode.cn/problems/minimum-edge-reversals-so-every-node-is-reachable/description/
*/
class Solution {
private:
    vector<vector<pair<int, int>>> graph;
    vector<int> ans;
    vector<int> f;

    void dfs(int u, int fa) {
        for (const auto &e : graph[u]) {
            if (e.first == fa)
                continue;

            dfs(e.first, u);
            f[u] += f[e.first] + e.second;
        }
    }

    void dfs2(int u, int fa, int r) {
        ans[u] = f[u] + r;

        for (const auto &e : graph[u]) {
            if (e.first == fa)
                continue;

            if (e.second == 0)
                dfs2(e.first, u, f[u] - f[e.first] + r + 1);
            else
                dfs2(e.first, u, f[u] - f[e.first] + r - 1);
        }
    }

public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for (const auto &e : edges) {
            graph[e[0]].emplace_back(e[1], 0);
            graph[e[1]].emplace_back(e[0], 1);
        }

        f.resize(n, 0);
        dfs(0, -1);

        ans.resize(n);
        dfs2(0, -1, 0);

        return ans;
    }
};
