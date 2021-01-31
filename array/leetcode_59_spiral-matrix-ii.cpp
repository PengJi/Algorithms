/**
 * 59. 螺旋矩阵 II
 * https://leetcode-cn.com/problems/spiral-matrix-ii/
 */

class Solution {
public:
    // 不断缩减边界
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, right = n-1, top = 0, bottom = n-1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int cur = 1, max = n * n;
        while(cur <= max) {
            for(int i = left; i <= right; i++) {
                ans[top][i] = cur++;
            }
            top++;
            for(int j = top; j <= bottom; j++) {
                ans[j][right] = cur++;
            }
            right--;
            for(int m = right; m >= left; m--) {
                ans[bottom][m] = cur++;
            }
            bottom--;
            for(int n = bottom; n >= top; n--) {
                ans[n][left] = cur++;
            }
            left++;
        }

        return ans;
    }
};
