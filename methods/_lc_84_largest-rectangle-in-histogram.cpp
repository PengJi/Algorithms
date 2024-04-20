/**
 * 84. 柱状图中最大的矩形
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 *
 * 可用于 85
 */

class Solution {
public:
    // 单调栈（递增）
    // 此题的本质是找到每个柱形条左侧第一个比自己低或相等，以及右侧第一个严格比自己低的矩形条，然后用宽度乘上当前柱形条的高度作为备选答案。
    // 解决此类问题的经典做法是单调栈，维护一个单调递增的栈，如果当前柱形条 i 的高度比栈顶要低，则栈顶元素 cur 出栈。
    // 出栈后，cur 右侧第一个严格比自己低的柱形条就是 i，左侧第一个比自己低或相等的柱形条是当前栈中的 top。
    // 不断出栈直到栈为空或者柱形条 i 不再比 top 低。
    // O(n)/O(n)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        // 为了算法书写方便，在数组末尾添加高度 -1
        // 这会使得栈中所有数字在最后出栈。
        heights.push_back(-1);
        stack<int> stk;

        for (int i = 0; i <= n; i++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int cur = stk.top();
                stk.pop();

                if (stk.empty()) {
                    res = max(res, heights[cur] * i);
                } else {
                    res = max(res, heights[cur] * (i - stk.top() - 1));
                }
            }

            stk.push(i);
        }

        return res;
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
