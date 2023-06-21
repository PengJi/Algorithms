/**
 * 2662. 前往目标的最小代价
 * https://leetcode.cn/problems/minimum-cost-of-a-path-with-special-roads/
*/
const int N = 410;

class Solution {
public:
    int w[N][N];
    int n, nx[N], ny[N], st, ed;
    int dis[N];
    bool vis[N];

    string encode(const vector<int> &p) {
        return to_string(p[0]) + " " + to_string(p[1]);
    }

    int minimumCost(vector<int>& start, vector<int>& target,
        vector<vector<int>>& specialRoads
    ) {
        memset(w, 0x3f, sizeof(w));

        unordered_map<string, int> seen;
        specialRoads.push_back({start[0], start[1], target[0], target[1], INT_MAX});

        n = 0;
        for (const auto &r : specialRoads) {
            string x = encode({r[0], r[1]});
            string y = encode({r[2], r[3]});
            if (seen.find(x) == seen.end()) {
                nx[n] = r[0]; ny[n] = r[1];
                if (r[0] == start[0] && r[1] == start[1]) st = n;
                if (r[0] == target[0] && r[1] == target[1]) ed = n;
                seen[x] = n++;
            }

            if (seen.find(y) == seen.end()) {
                nx[n] = r[2]; ny[n] = r[3];
                if (r[2] == start[0] && r[3] == start[1]) st = n;
                if (r[2] == target[0] && r[3] == target[1]) ed = n;
                seen[y] = n++;
            }

            int u = seen[x], v = seen[y];
            w[u][v] = min(w[u][v], r[4]);
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                w[i][j] = min(w[i][j], abs(nx[i] - nx[j]) + abs(ny[i] - ny[j]));

        memset(dis, 0x3f, sizeof(dis));
        memset(vis, false, sizeof(vis));

        dis[st] = 0;
        for (int it = 0; it < n; it++) {
            int mi = -1, mv = INT_MAX;
            for (int i = 0; i < n; i++)
                if (!vis[i] && mv > dis[i]) {
                    mv = dis[i];
                    mi = i;
                }

            if (mi == -1)
                break;

            vis[mi] = true;

            for (int i = 0; i < n; i++)
                dis[i] = min(dis[i], dis[mi] + w[mi][i]);
        }

        return dis[ed];
    }
};
