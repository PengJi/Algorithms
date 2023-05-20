class Solution {
public:
    vector<vector<int>> graph;
    vector<int> f, f1, f2;
    int ans;

    void solve1(int u, int fa, vector<int> &coins) {
        for (int v : graph[u]) {
            if (v == fa)
                continue;

            solve1(v, u, coins);

            if (f2[v] > 0)
                f[u] += f[v] + 2;

            f1[u] += coins[v];
            f2[u] += f1[v] + f2[v];
        }
    }

    void solve2(int u, int fa, int fa_f, int fa_f1, int fa_f2, vector<int> &coins) {
        if (fa_f2 > 0) ans = min(ans, f[u] + fa_f + 2);
        else ans = min(ans, f[u]);

        for (int v : graph[u]) {
            if (v == fa)
                continue;

            int new_fa_f = fa_f + (fa_f2 > 0 ? 2 : 0) + f[u];
            int new_fa_f1 = f1[u] - coins[v] + (fa != -1 ? coins[fa] : 0);
            int new_fa_f2 = fa_f1 + fa_f2 + f2[u];

            if (f2[v] > 0) {
                new_fa_f -= f[v] + 2;
                new_fa_f2 -= f1[v] + f2[v];
            }

            solve2(v, u, new_fa_f, new_fa_f1, new_fa_f2, coins);
        }
    }

    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        const int n = coins.size();

        graph.resize(n);

        for (const auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        f.resize(n, 0);
        f1.resize(n, 0);
        f2.resize(n, 0);

        solve1(0, -1, coins);

        ans = INT_MAX;

        solve2(0, -1, 0, 0, 0, coins);

        return ans;
    }
};
