/**
 * 1706. 球会落何处
 * https://leetcode-cn.com/problems/where-will-the-ball-fall/
 */

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> ans(col);

        for(int i = 0; i < col; i++) {
            ans[i] = i;
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(ans[j] == -1) {
                    continue;
                }

                if(grid[i][ans[j]] == 1 && ans[j] + 1 < col && grid[i][ans[j] + 1] == 1) {
                    ans[j]++;
                } else if(grid[i][ans[j]] == -1 && ans[j] - 1 >= 0 && grid[i][ans[j] - 1] == -1) {
                    ans[j]--;
                } else {
                    ans[j] = -1;
                }
            }
        }

        return ans;
    }
};
