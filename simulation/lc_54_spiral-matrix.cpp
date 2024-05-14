/**
 * 54. 螺旋矩阵
 * https://leetcode-cn.com/problems/spiral-matrix/
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        int up = 0, down = matrix.size() - 1;        // 上下边界
        int left = 0, right = matrix[0].size() - 1;  //左右边界
        vector<int> res;

        while (true) {
            // 从左到右
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[up][i]);
            }
            if (++up > down) break;  // 修改上边界

            // 从上到下
            for (int i = up; i <= down; i++) {
                res.push_back(matrix[i][right]);
            }
            if (--right < left) break;  // 修改右边界

            // 从右到左
            for (int i = right; i >= left; i--) {
                res.push_back(matrix[down][i]);
            }
            if (--down < up) break;  // 修改下边界

            // 从下到上
            for (int i = down; i >= up; i--) {
                res.push_back(matrix[i][left]);
            }
            if (++left > right) break;  // 修改左边界
        }

        return res;
    }
};

class Solution {
public:
    // 依次遍历四个方向
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 更行的方向
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        vector<int> res;

        // 记录是否访问过
        vector<vector<bool>> st(m, vector<bool>(n));
        // 前进的方向
        int d = 0;
        // 下一个坐标
        int tx = 0, ty = 0;
        for (int i = 0, x = 0, y = 0; i < m * n; i++) {
            res.push_back(matrix[x][y]);
            st[x][y] = true;

            // 更新下个坐标
            tx = x + dx[d], ty = y + dy[d];
            // 下个位置是否符合要求
            if (tx < 0 || tx >= m || ty < 0 || ty >= n || st[tx][ty]) {
                d = (d + 1) % 4;
                // 更新下个坐标
                tx = x + dx[d], ty = y + dy[d];
            }

            // 更新下个坐标
            x = tx, y = ty;
        }

        return res;
    }
};
