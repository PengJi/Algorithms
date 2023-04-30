class Solution {
private:
    int n;
    vector<vector<int>> graph;
    vector<unordered_set<int>> p;

    vector<int> f;

    int ans;

    void dfs1(int u, int fa) {
        f[u] = 0;

        for (int v : graph[u]) {
            if (v == fa)
                continue;

            dfs1(v, u);
            f[u] += f[v];

            if (p[u].find(v) != p[u].end())
                ++f[u];
        }
    }

    void dfs2(int u, int fa, int from, int k) {
        if (f[u] + from >= k)
            ans++;

        for (int v : graph[u]) {
            if (v == fa)
                continue;

            int t = 0;
            if (p[u].find(v) != p[u].end()) --t;
            if (p[v].find(u) != p[v].end()) ++t;

            dfs2(v, u, from + f[u] - f[v] + t, k);
        }
    }

public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        n = edges.size() + 1;
        graph.resize(n);

        for (const auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        p.resize(n);
        for (const auto &e : guesses)
            p[e[0]].insert(e[1]);

        f.resize(n);

        dfs1(0, -1);

        ans = 0;

        dfs2(0, -1, 0, k);

        return ans;
    }
};
