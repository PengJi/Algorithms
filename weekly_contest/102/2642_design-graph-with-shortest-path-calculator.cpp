/**
 * 2642. 设计可以求最短路径的图类
 * https://leetcode.cn/problems/design-graph-with-shortest-path-calculator/
*/
const int INF = 1000000000;

class Graph {
private:
    int n;
    vector<vector<int>> graph;

public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph.resize(n, vector<int>(n, INF));

        for (const auto &e : edges)
            graph[e[0]][e[1]] = e[2];
    }

    void addEdge(vector<int> edge) {
        graph[edge[0]][edge[1]] = edge[2];
    }

    int shortestPath(int node1, int node2) {
        vector<int> d(n, INF);
        vector<bool> v(n, false);

        d[node1] = 0;

        for (int i = 0; i < n; i++) {
            int mw = INF, mp = -1;
            for (int j = 0; j < n; j++)
                if (!v[j] && mw > d[j]) {
                    mw = d[j];
                    mp = j;
                }

            if (mw == INF)
                break;

            v[mp] = true;

            for (int j = 0; j < n; j++)
                d[j] = min(d[j], d[mp] + graph[mp][j]);
        }

        if (d[node2] == INF)
            return -1;

        return d[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */