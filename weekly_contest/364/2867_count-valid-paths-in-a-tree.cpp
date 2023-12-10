/**
 * 2867. 统计树中的合法路径数目
 * https://leetcode.cn/problems/count-valid-paths-in-a-tree/description/
*/
#define LL long long

class Solution {
private:
    vector<bool> is_not_prime;
    vector<int> prime;

    vector<vector<int>> graph;
    LL ans;

    void init_prime(int n) {
        is_not_prime.resize(n + 1, false);
        is_not_prime[1] = true;

        for (int i = 2; i <= n; i++) {
            if (!is_not_prime[i])
                prime.push_back(i);

            for (int j = 0; i * prime[j] <= n; j++) {
                is_not_prime[i * prime[j]] = true;
                if (i % prime[j] == 0)
                    break;
            }
        }
    }

    pair<LL, LL> solve(int u, int fa) {
        LL f = 0, g = 0;

        for (int v : graph[u]) {
            if (v == fa)
                continue;

            auto res = solve(v, u);
            if (is_not_prime[u])
                ans += f * res.second + (g + 1) * res.first;
            else
                ans += (g + 1) * res.second;

            f += res.first;
            g += res.second;
        }

        if (is_not_prime[u])
            return make_pair(f, g + 1);

        return make_pair(g + 1, 0);
    }

public:
    LL countPaths(int n, vector<vector<int>>& edges) {
        init_prime(n);

        graph.resize(n + 1);

        for (const auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        ans = 0;
        solve(1, 0);

        return ans;
    }
};
