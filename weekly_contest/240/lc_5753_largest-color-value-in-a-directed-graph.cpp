/**
 * 5753. 有向图中最大颜色值
 * https://leetcode-cn.com/problems/largest-color-value-in-a-directed-graph/
 */

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/1212430/
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> g(n), f(n, vector<int>(26));
        vector<int> d(n), p;
        for (auto& e: edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            d[b] ++ ;
        }
        queue<int> q;
        for (int i = 0; i < n; i ++ )
            if (!d[i])
                q.push(i);

        while (q.size()) {
            auto t = q.front();
            q.pop();
            p.push_back(t);

            for (int j: g[t])
                if (! -- d[j])
                    q.push(j);
        }

        if (p.size() < n) return -1;
        int res = 0;
        for (int i: p) {
            int c = colors[i] - 'a';
            f[i][c] = max(f[i][c], 1);
            for (int j = 0; j < 26; j ++ ) {
                for (int k: g[i]) {
                    int t = 0;
                    if (colors[k] - 'a' == j) t = 1;
                    f[k][j] = max(f[k][j], f[i][j] + t);
                }
                res = max(res, f[i][j]);
            }
        }

        return res;
    }
};
