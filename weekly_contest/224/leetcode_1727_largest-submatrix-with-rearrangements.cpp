/**
 * 1727. 重新排列后的最大子矩阵
 * https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements/solution/tan-xin-huo-xue-huo-yong-zuo-ti-bu-huang-5f8v/
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> up(row, vector<int>(col, 0));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 1) {
                    up[i][j] = (i == 0 ? 0 : up[i-1][j]) + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < row; i++) {
            vector<int> vec;
            for (int j = 0; j < col; j++) {
                vec.push_back(up[i][j]);
            }

            sort(vec.begin(), vec.end());

            for (int j = 0; j < col; j++) {
                ans = max(ans, vec[j] * (col - j));
            }
        }
        return ans;
    }
};
