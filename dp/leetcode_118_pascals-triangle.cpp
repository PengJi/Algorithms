/**
 * 118. 杨辉三角
 * https://leetcode-cn.com/problems/pascals-triangle/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/pascals-triangle/solution/cshuang-bai-by-rjs/
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for(int i=0; i<numRows; i++) {
            res.push_back(vector<int>(i+1, 1));
        }

        for(int i=0; i<numRows; i++) {
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }

        return res;
    }
};