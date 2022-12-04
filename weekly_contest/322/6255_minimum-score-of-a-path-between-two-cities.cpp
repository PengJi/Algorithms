/**
 * 6255. 两个城市间路径的最小分数
 * https://leetcode.cn/problems/minimum-score-of-a-path-between-two-cities/description/
*/

class Solution {
public:
    vector<int> p;

    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // 使用并查集，同时存储每个集合中的最小分数
    int minScore(int n, vector<vector<int>>& roads) {
        p.resize(n+1);
        vector<int> w(n+1, 1e8);

        for(int i = 1; i <= n; i++) p[i] = i;
        for(auto &vec : roads) {
            int a = find(vec[0]), b = find(vec[1]), c = vec[2];
            w[a] = min({w[a], w[b], c});
            p[b] = a;
        }

        return w[find(1)];
    }
};
