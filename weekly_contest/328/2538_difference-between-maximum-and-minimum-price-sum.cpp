#define LL long long

class Solution {
private:
    vector<vector<int>> graph;
    vector<LL> f;
    LL res;

    void solve1(int u, int fa, const vector<int> &price) {
        for (int v : graph[u]) {
            if (v == fa)
                continue;

            solve1(v, u, price);
            f[u] = max(f[u], f[v]);
        }

        res = max(res, f[u]);

        f[u] += price[u];
    }

    void solve2(int u, int fa, LL prev, const vector<int> &price) {
        res = max(res, prev);

        LL ma = 0, ma2 = 0;
        for (int v : graph[u]) {
            if (v == fa)
                continue;

            if (ma < f[v]) {
                ma2 = ma;
                ma = f[v];
            } else if (ma2 < f[v]) {
                ma2 = f[v];
            }
        }

        for (int v : graph[u]) {
            if (v == fa)
                continue;

            if (ma == f[v])
                solve2(v, u, max(prev, ma2) + price[u], price);
            else
                solve2(v, u, max(prev, ma) + price[u], price);
        }
    }

public:
    LL maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        graph.resize(n);
        for (const auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        f.resize(n, 0);
        res = 0;

        solve1(0, -1, price);
        solve2(0, -1, 0, price);

        return res;
    }
};
