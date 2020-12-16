/**
 * 48. 旋转图像
 * 给定一个 n × n 的二维矩阵表示一个图像。
 * 将图像顺时针旋转 90 度。
 * 
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
