/**
 * 1727. 重新排列后的最大子矩阵
 * https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements/solution/tan-xin-huo-xue-huo-yong-zuo-ti-bu-huang-5f8v/
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int h = matrix.size(), w = matrix[0].size();
        vector<vector<int>> up(h, vector<int>(w, 0));
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (matrix[i][j] == 1) {
                    up[i][j] = (i == 0 ? 0 : up[i-1][j]) + 1;
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < h; i++) {
            vector<int> buf;
            for (int j = 0; j < w; j++) {
                buf.push_back(up[i][j]);
            }
            sort(buf.begin(), buf.end());
            for (int j = 0; j < w; j++) {
                ret = max(ret, buf[j] * (w - j));
            }
        }
        return ret;
    }
};
