/**
 * 2742. 给墙壁刷油漆
 * https://leetcode.cn/problems/painting-the-walls/description/
*/

class Solution {
public:
    // DP
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        const int INF = 1e9;
        // 背包 dp 的空间优化，可以把第一维压掉
        int f[n + 1];
        for (int j = 0; j <= n; j++) f[j] = INF;
        f[0] = 0;

        for (int i = 0; i < n; i++) for (int j = n; j >= 0; j--)
            f[j] = min(f[j], f[max(j - time[i] - 1, 0)] + cost[i]);
        
        return f[n];
    }
};
