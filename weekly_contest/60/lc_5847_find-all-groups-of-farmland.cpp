/**
 * 5847. 找到所有的农场组
 * https://leetcode-cn.com/problems/find-all-groups-of-farmland/
 */
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> res;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][j]) {
                    int x = i, y = j;
                    for(int a = i; a < m && g[a][j]; a++) {
                        for(int b = j; b < n && g[a][b]; b++) {
                            g[a][b] = 0;
                            x = max(a, x), y = max(b, y);
                        }
                    }
                    res.push_back({i, j, x, y});
                }
            }
        }

        return res;
    }
};
