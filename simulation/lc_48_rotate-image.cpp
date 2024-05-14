/**
 * 48. 旋转图像
 * https://leetcode-cn.com/problems/rotate-image/
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int tmp;
        // 矩阵转置
        for(int i = 0; i < len; i++) {
            for(int j = i; j < len; j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        // 每一行逆序
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len/2; j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[i][len-j-1];
                matrix[i][len-j-1] = tmp;
            }
        }
    }
};
