/**
 * 547. 省份数量
 * https://leetcode-cn.com/problems/number-of-provinces/
 */

class Solution {
public:
    vector<int> p;

    // 并查集
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = n;
        for (int i = 0; i < n; i++) p.push_back(i);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] && find(i) != find(j)) {
                    p[find(i)] = find(j);
                    res--;
                }
            }
        }

        return res;
    }
};
