/**
 * 2685. 统计完全连通分量的数量
 * https://leetcode.cn/problems/count-the-number-of-complete-components/
*/
class Solution {
public:
    vector<bool> seen;
    vector<vector<int>> graph;

    int check(int st, int n) {
        seen[st] = true;
        queue<int> q;
        q.push(st);

        int sz = 0, tot = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ++sz;
            tot += graph[u].size();

            for (int v : graph[u])
                if (!seen[v]) {
                    seen[v] = true;
                    q.push(v);
                }
        }

        return tot == sz * (sz - 1);
    }

    // 宽度优先遍历
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for (const auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        seen.resize(n, false);

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (!seen[i])
                ans += check(i, n);

        return ans;
    }
};
