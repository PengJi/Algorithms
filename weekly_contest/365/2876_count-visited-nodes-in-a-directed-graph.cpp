/**
 * 2876. 有向图访问计数
 * https://leetcode.cn/problems/count-visited-nodes-in-a-directed-graph/description/
*/
class Solution {
private:
    int n;
    vector<int> indegs, ans;

    void topsort(const vector<int> &edges) {
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegs[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (--indegs[edges[u]] == 0)
                q.push(edges[u]);
        }
    }

    void init_loop_ans(const vector<int> &edges) {
        for (int i = 0; i < n; i++) {
            if (indegs[i] == 0 || ans[i] > 0)
                continue;

            vector<int> t;
            int j = i;
            do {
                t.push_back(j);
                j = edges[j];
            } while (j != i);

            for (int u : t)
                ans[u] = t.size();
        }
    }

    void dfs(int u, const vector<int> &edges) {
        int v = edges[u];
        if (ans[v] == 0)
            dfs(v, edges);

        ans[u] = ans[v] + 1;
    }

public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        n = edges.size();
        indegs.resize(n, 0);

        for (int i = 0; i < n; i++)
            ++indegs[edges[i]];

        topsort(edges);

        ans.resize(n, 0);
        init_loop_ans(edges);

        for (int i = 0; i < n; i++)
            if (ans[i] == 0)
                dfs(i, edges);

        return ans;
    }
};
