class Solution {
public:
    // 暴力枚举
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        const int n = vals.size();

        vector<vector<int>> adj(n);

        for (const auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MIN;

        for (int u = 0; u < n; u++) {
            sort(adj[u].begin(), adj[u].end(), [&](int x, int y) {
                return vals[x] > vals[y];
            });

            int r = vals[u];
            for (int i = 0; i < adj[u].size() && i < k && vals[adj[u][i]] > 0; i++)
                r += vals[adj[u][i]];

            ans = max(ans, r);
        }

        return ans;
    }
};
