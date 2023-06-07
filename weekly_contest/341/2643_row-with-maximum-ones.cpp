/**
 * 2643. 一最多的行
 * https://leetcode.cn/problems/row-with-maximum-ones/
*/
class Solution {
public:
    // 模拟
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int res = -1, row;

        for (int i = 0; i < mat.size(); i++) {
            int cnt = 0;
            for (int x : mat[i])
                cnt += x;

            if (res < cnt) {
                res = cnt;
                row = i;
            }
        }

        return {row, res};
    }
};
