/**
 * 2830. 销售利润最大化
 * https://leetcode.cn/problems/maximize-the-profit-as-the-salesman/description/
*/
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<vector<int>> p(n + 1);

        for (int i = 0; i < offers.size(); i++)
            p[offers[i][1] + 1].push_back(i);

        const int m = offers.size();
        vector<int> f(n + 1);
        f[0] = 0;

        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1];
            for (int x : p[i])
                f[i] = max(f[i], f[offers[x][0]] + offers[x][2]);
        }

        return f[n];
    }
};
