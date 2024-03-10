/**
 * 207. 课程表
 * https://leetcode.cn/problems/course-schedule/
 */

class Solution {
public:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

    // https://leetcode-cn.com/problems/course-schedule/solution/ke-cheng-biao-by-leetcode-solution/DFS_BFS/leetcode_207_course-schedule.cpp
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }

    void dfs(int u) {
        visited[u] = 1;
        for (int v : edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            } else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }
};

class Solution {
public:
    // 有向无环图的拓扑排序
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> g(n);
        vector<int> d(n);

        // 组建有向无环图
        for (auto& x : p) {
            int a = x[0], b = x[1];
            g[b].push_back(a);  // 建立边，b 指向 a
            d[a]++;             // 统计入度，a 的入度加一
        }

        queue<int> q;  // 存储入度为 0 的点
        for (int i = 0; i < n; i++) {
            if (d[i] == 0) q.push(i);
        }

        // 有向无环图去除边
        int cnt = 0;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            cnt++;
            for (auto x : g[t]) {
                if (--d[x] == 0) q.push(x);
            }
        }

        return cnt == n;  // 有向无环图中，入度为 0 的点应该与总节点数相同
    }
};
