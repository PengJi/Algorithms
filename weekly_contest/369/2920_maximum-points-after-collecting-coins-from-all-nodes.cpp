/**
 * 2920. 收集所有金币可获得的最大积分
 * https://leetcode.cn/problems/maximum-points-after-collecting-coins-from-all-nodes/description/
*/
const int N = 100010, M = 15;

class Solution {
private:
    vector<vector<int>> graph;
    int f[N][M];

    void solve(int u, int fa, const vector<int> &coins, int k) {
        int t[M + 1];
        memset(t, 0, sizeof(t));

        for (int v : graph[u]) {
            if (v == fa)
                continue;

            solve(v, u, coins, k);
            for (int j = 0; j < M; j++) {
                t[j] += f[v][j];
            }
        }

        int x = coins[u];
        for (int j = 0; j < M; j++) {
            f[u][j] = max(t[j] + x - k, t[j + 1] + x / 2);
            x /= 2;
        }
    }

public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        const int n = coins.size();
        graph.resize(n);
        for (const auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        solve(0, -1, coins, k);

        int ans = 0;
        for (int j = 0; j < M; j++)
            ans = max(ans, f[0][j]);

        return ans;
    }
};
