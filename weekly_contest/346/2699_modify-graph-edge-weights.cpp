/**
 * 2699. 修改图中的边权
 * https://leetcode.cn/problems/modify-graph-edge-weights/description/
*/

const int N = 110;
const int INF = 2000000000;

class Solution {
private:
    int w[N][N], d[N];
    bool v[N];

    int dijkstra(int n, int s, int t) {
        for (int i = 0; i < n; i++) {
            d[i] = INF;
            v[i] = false;
        }

        d[s] = 0;
        for (int it = 0; it < n; it++) {
            int mind = INF, x;
            for (int u = 0; u < n; u++)
                if (!v[u] && mind > d[u]) {
                    mind = d[u];
                    x = u;
                }

            if (mind == INF)
                break;

            v[x] = true;

            for (int y = 0; y < n; y++)
                if (w[x][y] != -1 && w[x][y] != INF)
                    d[y] = min(d[y], d[x] + w[x][y]);
        }

        return d[t];
    }

    void get_ans(vector<vector<int>> &edges) {
        for (auto &e : edges)
            if (e[2] == -1)
                e[2] = INF;
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges,
        int source, int destination, int target
    ) {
        const int m = edges.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                w[i][j] = INF;

        vector<int> modified;
        for (int i = 0; i < m; i++) {
            int x = edges[i][0], y = edges[i][1], z = edges[i][2];
            w[x][y] = w[y][x] = z;
            if (z == -1)
                modified.push_back(i);
        }

        int r = dijkstra(n, source, destination);
        if (r < target)
            return {};

        if (r == target) {
            get_ans(edges);

            return edges;
        }

        for (int i : modified) {
            auto &e = edges[i];
            w[e[0]][e[1]] = w[e[1]][e[0]] = 1;

            int r = dijkstra(n, source, destination);
            if (r <= target) {
                e[2] = target - r + 1;
                get_ans(edges);

                return edges;
            }

            e[2] = 1;
        }

        return {};
    }
};
