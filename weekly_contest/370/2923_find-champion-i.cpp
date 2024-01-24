/**
 * 2923. 找到冠军 I
 * https://leetcode.cn/problems/find-champion-i/description/
*/
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        const int n = grid.size();
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < n; j++)
                if (i != j && grid[i][j] == 0) {
                    ok = false;

                    break;
                }

            if (ok)
                return i;
        }

        return -1;
    }
};
