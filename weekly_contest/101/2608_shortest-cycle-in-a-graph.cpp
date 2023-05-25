class Solution {
public:
    vector<vector<int>> graph;
    queue<int> q;

    int bfs(int st, int ed, int n) {
        q.push(st);

        vector<int> d(n, INT_MAX);
        d[st] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u])
                if (d[v] > d[u] + 1 && !(u == st && v == ed)) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
        }

        return d[ed];
    }

    // 宽度优先遍历
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        graph.resize(n);

        for (const auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int ans = INT_MAX;
        for (const auto &e : edges)
            ans = min(ans, bfs(e[0], e[1], n));

        if (ans == INT_MAX)
            return -1;

        return ans + 1;
    }
};
