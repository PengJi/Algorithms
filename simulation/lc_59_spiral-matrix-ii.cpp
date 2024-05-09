/**
 * 59. 螺旋矩阵 II
 * https://leetcode-cn.com/problems/spiral-matrix-ii/
 */

class Solution {
public:
    // 不断缩减边界
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int cur = 1, max = n * n;
        while (cur <= max) {
            for (int i = left; i <= right; i++) {
                ans[top][i] = cur++;
            }
            top++;

            for (int j = top; j <= bottom; j++) {
                ans[j][right] = cur++;
            }
            right--;

            for (int m = right; m >= left; m--) {
                ans[bottom][m] = cur++;
            }
            bottom--;

            for (int n = bottom; n >= top; n--) {
                ans[n][left] = cur++;
            }
            left++;
        }

        return ans;
    }
};

class Solution {
public:
    // 定义四个方向，然后依次遍历
    vector<vector<int>> generateMatrix(int n) {
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};  // 方向
        int d = 0, tmpx = 0, tmpy = 0;                   // 前进的方向
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 1, x = 0, y = 0; i <= n * n; i++) {
            res[x][y] = i;
            tmpx = x + dx[d], tmpy = y + dy[d];  // 计算下一个坐标
            // 判断是否越界
            if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= n || res[tmpx][tmpy]) {
                d = (d + 1) % 4;
                tmpx = x + dx[d], tmpy = y + dy[d];  // 更新下一个坐标
            }
            x = tmpx, y = tmpy;
        }

        return res;
    }
};
