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
        for (const auto& info: prerequisites) {
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
        for (int v: edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }
};

class Solution {
public:
    // 拓扑排序
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for (auto& e: edges) {
            int b = e[0], a = e[1];
            g[a].push_back(b);
            d[b] ++ ;
        }

        queue<int> q;
        for (int i = 0; i < n; i ++ )
            if (d[i] == 0)
                q.push(i);

        int cnt = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            cnt ++ ;
            for (auto i : g[t])
                if ( -- d[i] == 0)
                    q.push(i);
        }

        return cnt == n;
    }
};

