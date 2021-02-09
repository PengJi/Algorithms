/**
 * 剑指 Offer 04. 二维数组中的查找
 * https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 */

class Solution {
public:
    // 遍历
    // 时间复杂度：O(m+n)
    // 空间复杂度：O(1)
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;

        int rows = matrix.size(), cols = matrix[0].size();
        int r = 0, c = cols - 1;
        while(r < rows && c >= 0) {  // 从右上角开始查找
            if(matrix[r][c] == target)  // 找到目标值
                return true;
            else if(matrix[r][c] > target)  // 大于目标值，从右向左查找
                c--;
            else  // 小于目标值，从上向下查找
                r++;
        }

        return false;
    }
};
