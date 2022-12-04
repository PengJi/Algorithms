/**
 * 6256. 将节点分成尽可能多的组
 * https://leetcode.cn/problems/divide-nodes-into-the-maximum-number-of-groups/description/
*/

class Solution {
public:
    const int INF = 1e8;
    int n;
    vector<int> p;
    vector<vector<int>> d;
    vector<vector<int>> g;
    vector<int> dist;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void bfs(int start) {
        for (int i = 1; i <= n; i ++ ) dist[i] = INF;
        dist[start] = 0;
        queue<int> q;
        q.push(start);

        while (q.size()) {
            auto t = q.front();
            q.pop();

            for (auto x: g[t]) {
                if (dist[x] > dist[t] + 1) {
                    dist[x] = dist[t] + 1;
                    q.push(x);
                }
            }
        }

        for (int i = 1; i <= n; i ++ )
            d[start][i] = dist[i];
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        this->n = n;
        p.resize(n + 1);
        dist.resize(n + 1);
        g = vector<vector<int>>(n + 1);
        d = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
        for (int i = 1; i <= n; i ++ ) {
            d[i][i] = 0;
            p[i] = i;
        }

        for (auto& edge: edges) {
            int a = edge[0], b = edge[1];
            g[a].push_back(b);
            g[b].push_back(a);

            p[find(a)] = find(b);
        }

        for (int i = 1; i <= n; i ++ ) bfs(i);

        vector<vector<int>> vers(n + 1);
        for (int i = 1; i <= n; i ++ )
            vers[find(i)].push_back(i);

        int res = 0;
        for (auto& vs: vers) {
            if (vs.empty()) continue;
            int mx = 0;
            for (int start: vs) {
                for (auto& edge: edges) {
                    int a = edge[0], b = edge[1];
                    if (d[start][a] < INF && d[start][a] == d[start][b]) {
                        return -1;
                    }
                }
                for (auto end: vs)
                    mx = max(mx, d[start][end]);
            }
            res += mx + 1;
        }

        return res;
    }
};
