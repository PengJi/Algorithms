/**
 * 84. 柱状图中最大的矩形
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 *
 * 可用于 85
 */

class Solution {
public:
    // 单调栈（递增）
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int largestRectangleArea(vector<int>& heights) {
    }
};

class Solution {
public:
    // 暴力法（超出时间限制）
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if (len == 0) return 0;

        int max = 0, tmpArea, tmpMinHeight;
        for (int i = 0; i < len; i++) {
            tmpMinHeight = heights[i];
            for (int j = i; j < len; j++) {
                if (tmpMinHeight > heights[j]) {
                    tmpMinHeight = heights[j];
                }
                tmpArea = tmpMinHeight * (j - i + 1);
                if (tmpArea > max) {
                    max = tmpArea;
                }
            }
        }

        return max;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> left(n), right(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            while (stk.size() && heights[i] <= heights[stk.top()]) stk.pop();
            if (stk.size())
                left[i] = stk.top();
            else
                left[i] = -1;
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && heights[i] <= heights[stk.top()]) stk.pop();
            if (stk.size())
                right[i] = stk.top();
            else
                right[i] = n;
            stk.push(i);
        }

        int tmp;
        for (int i = 0; i < n; i++) {
            tmp = heights[i] * (right[i] - left[i] - 1);
            if (tmp > res) res = tmp;
        }

        return res;
    }
};
