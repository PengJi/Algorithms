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

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> left(n), right(n);
        int res = 0;
        for(int i = 0; i < n; i++) {
            while(stk.size() && heights[i] <= heights[stk.top()]) stk.pop();
            if(stk.size()) left[i] = stk.top();
            else left[i] = -1;
            stk.push(i);
        }

        while(!stk.empty()) stk.pop();

        for(int i = n-1; i >= 0; i-- ) {
            while(stk.size() && heights[i] <= heights[stk.top()]) stk.pop();
            if(stk.size()) right[i] = stk.top();
            else right[i] = n;
            stk.push(i);
        }

        int tmp;
        for(int i = 0; i < n; i++) {
            tmp = heights[i] * (right[i] - left[i] -1);
            if(tmp > res) res = tmp;
        }

        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> h(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    if(i) h[i][j] = 1 + h[i-1][j];
                    else h[i][j] = 1;
                }
            }
        }

        int tmp = 0, res = 0;
        for(int i = 0; i < n; i++) {
            tmp = largestRectangleArea(h[i]);
            if(tmp > res) res = tmp;
        }

        return res;
    }
};
