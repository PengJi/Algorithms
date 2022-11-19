class Solution {
private:
    vector<vector<int>> graph;
    vector<int> dis, points;

    void get_dis(int u, int fa) {
        if (dis[u] != -1)
            return;

        for (int v : graph[u]) {
            if (v == fa)
                continue;

            get_dis(v, u);

            if (dis[v] != -1) {
                dis[u] = dis[v] + 1;

                break;
            }
        }
    }

    void solve(int u, int fa, int step, const vector<int> &amount) {
        bool first = true;
        points[u] = 0;

        for (int v : graph[u]) {
            if (v == fa)
                continue;

            solve(v, u, step + 1, amount);

            if (first) points[u] = points[v];
            else points[u] = max(points[u], points[v]);

            first = false;
        }

        if (dis[u] == -1 || step < dis[u])
            points[u] += amount[u];
        else if (step == dis[u])
            points[u] += amount[u] / 2;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        const int n = amount.size();

        graph.resize(n);
        for (const auto &v : edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }

        dis.resize(n, -1);
        dis[bob] = 0;
        get_dis(0, -1);

        points.resize(n);
        solve(0, -1, 0, amount);

        return points[0];
    }
};
