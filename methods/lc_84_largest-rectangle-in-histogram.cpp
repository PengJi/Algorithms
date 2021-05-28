/**
 * 84. 柱状图中最大的矩形
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 */

class Solution {
public:
    // 单调栈（递增）
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;

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
    
    // 暴力法（超出时间限制）
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if(len == 0) return 0;

        int max = 0, tmpArea, tmpMinHeight;
        for(int i = 0; i < len; i++){
            tmpMinHeight = heights[i];
            for(int j = i; j < len; j++){
                if(tmpMinHeight > heights[j]){
                    tmpMinHeight = heights[j];
                }
                tmpArea = tmpMinHeight * (j - i + 1);
                if(tmpArea > max){ 
                    max = tmpArea;
                }
            }
        }

        return max;
    }
};
