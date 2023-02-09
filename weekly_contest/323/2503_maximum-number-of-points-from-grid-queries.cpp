const int N = 100010;

struct Node {
    int x, y, val;
    bool operator<(const Node& t) const {
        return val < t.val;
    }
}node[N];

class Solution {
public:
    int n, m;
    vector<int> p, sz;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int getId(int x, int y) {
        return x * m + y;
    }

    // 并查集
    vector<int> maxPoints(vector<vector<int>>& g, vector<int>& queries) {
        n = g.size(), m = g[0].size();
        vector<int> pos(queries.size()), res(queries.size());
        for (int i = 0; i < pos.size(); i ++ ) pos[i] = i;
        sort(pos.begin(), pos.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        for (int i = 0; i < n * m; i ++ ) {
            p.push_back(i);
            sz.push_back(1);
        }

        for (int i = 0, k = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++, k ++ ) {
                node[k] = {i, j, g[i][j]};
            }
        }

        sort(node, node + n * m);

        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

        int i = 0;
        for (auto k: pos) {
            int query = queries[k];

            while (i < n * m && node[i].val < query) {
                int x = node[i].x, y = node[i].y, val = node[i].val;
                i ++ ;
                for (int j = 0; j < 4; j ++ ) {
                    int a = x + dx[j], b = y + dy[j];
                    if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] < query) {
                        int u = getId(x, y), v = getId(a, b);
                        u = find(u), v = find(v);
                        if (u != v) {
                            sz[v] += sz[u];
                            p[u] = v;
                        }
                    }
                }
            }

            if (g[0][0] < query)
                res[k] = sz[find(0)];
        }

        return res;
    }
};
