class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};

        int up = 0, down = matrix.size()-1;  // 上下边界
        int left = 0, right = matrix[0].size()-1;  //左右边界
        vector<int> res;

        while(true) {
            // 从左到右
            for(int i = left; i <= right; i++) {
                res.push_back(matrix[up][i]);
            }
            if(++up > down) break;  // 修改上边界

            // 从上到下
            for(int i = up; i <= down; i++) {
                res.push_back(matrix[i][right]);
            }
            if(--right < left) break;  // 修改右边界

            // 从右到左
            for(int i = right; i >= left; i--) {
                res.push_back(matrix[down][i]);
            }
            if(--down < up) break;  // 修改下边界

            // 从下到上
            for(int i = down; i >= up; i--) {
                res.push_back(matrix[i][left]);
            }
            if(++left > right) break;  // 修改左边界
        }

        return res;
    }
};