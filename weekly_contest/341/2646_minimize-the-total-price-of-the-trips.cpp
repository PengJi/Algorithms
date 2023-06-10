/**
 * 2646. 最小化旅行的价格总和
 * https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/
*/
const int N = 50;

class Solution {
public:
    vector<int> graph[N], query[N];
    int fa[N], uni[N], w[N], dp[N][2];
    bool vis[N];

    int find(int x) {
        return x == uni[x] ? x : uni[x] = find(uni[x]);
    }

    void tarjan(int u, int p) {
        fa[u] = p;

        for (int v : graph[u]) {
            if (v == p) continue;

            tarjan(v, u);
            uni[v] = u;
        }

        vis[u] = true;

        for (int v: query[u]) {
            if (!vis[v]) continue;

            int lca = find(v);
            --w[lca];
            if (lca > 0) --w[fa[lca]];
        }
    }

    void solve(int u, const vector<int> &price) {
        dp[u][0] = dp[u][1] = 0;

        for (int v : graph[u]) {
            if (v == fa[u]) continue;

            solve(v, price);
            w[u] += w[v];

            dp[u][0] += min(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }

        dp[u][0] += price[u] * w[u];
        dp[u][1] += price[u] / 2 * w[u];
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price,
        vector<vector<int>>& trips
    ) {
        for (const auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        memset(w, 0, sizeof(w));
        for (int i = 0; i < trips.size(); i++) {
            int u = trips[i][0], v = trips[i][1];
            ++w[u]; ++w[v];

            query[u].push_back(v);
            if (u != v) query[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
            uni[i] = i;

        memset(vis, false, sizeof(vis));

        tarjan(0, -1);
        solve(0, price);

        return min(dp[0][0], dp[0][1]);
    }
};
