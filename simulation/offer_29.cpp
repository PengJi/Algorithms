/**
 * 剑指 Offer 29. 顺时针打印矩阵
 * https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
 */

class Solution {
public:
    // 遍历，缩小边界
    // 时间复杂度：O(mn)
    // 空间复杂度：O(1)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        int left = 0, right = matrix[0].size()-1;
        int bottom = matrix.size()-1, top = 0;
        vector<int> ans;
        while(true) {
            for(int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            if(++top > bottom) break;

            for(int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            if(left > --right) break;

            for(int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            if(top > --bottom) break;

            for(int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            if(++left > right) break;
        }

        return ans;
    }
};
