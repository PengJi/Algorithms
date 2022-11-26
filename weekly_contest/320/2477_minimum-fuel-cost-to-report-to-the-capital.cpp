/**
 * 2477. 到达首都的最少油耗
 * https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/
*/
#define LL long long

class Solution {
private:
    vector<vector<int>> graph;

    pair<int, LL> solve(int u, int fa, int seats) {
        int num = 1;
        LL cost = 0;

        for (int v : graph[u]) {
            if (v == fa)
                continue;

            auto p = solve(v, u, seats);
            num += p.first;
            cost += p.second + p.first / seats + bool(p.first % seats);
        }

        return make_pair(num, cost);
    }

public:
    LL minimumFuelCost(vector<vector<int>>& roads, int seats) {
        const int n = roads.size() + 1;

        graph.resize(n);

        for (const auto &e : roads) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        return solve(0, -1, seats).second;
    }
};
