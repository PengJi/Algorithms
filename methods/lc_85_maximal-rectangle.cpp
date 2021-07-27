/**
 * 85. 最大矩形
 * https://leetcode-cn.com/problems/maximal-rectangle/
 * 
 * 与 84 相关联
 */

class Solution {
public:
    // 单调栈
    // O(n^2)
    // O(n)
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int ans = 0;
        vector<int> height(col, 0);
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                } else {
                    height[j] = 0;
                }
            }
            ans = max(ans, findMaxArea(height));
        }

        return ans;
    }

    // 利用单调栈查找最大值
    int findMaxArea(vector<int> heights) {
        heights.insert(heights.begin(), 0);  // 在队首插入0
        heights.push_back(0);  // 在队尾插入0

        int res = 0;
        int cur, left, right;
        stack<int> stk;
        for(int i = 0; i < heights.size(); i++) {
            while(!stk.empty() && heights[i] < heights[stk.top()]) {
                cur = stk.top();
                stk.pop();
                left = stk.top() + 1;
                right = i - 1;
                res = max(res, (right-left+1) * heights[cur]);
            }
            stk.push(i);
        }

        return res;  
    }
};
