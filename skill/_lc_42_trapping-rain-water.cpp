/**
 * 42. 接雨水
 * https://leetcode-cn.com/problems/trapping-rain-water/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/121/
    // 单调栈（ACK）
    // 考虑每个位置左边和右边 第一个 比自身不低的矩形条，以及三个矩形条构成的 U 型，相当于对水的面积按 行 进行拆解。
    // 维护严格单调递减的单调栈。在每次检查栈顶要出栈时，i 为右边第一个比 st.top() 不低的矩形，st.top() 弹出栈顶，并将其记为 top。
    // 假设此时栈中仍然存在矩形，现在 st.top()（弹栈后的栈顶）、top 与 i 三个位置构成一个 U 型，其中 top 位置代表 U 型的底部，
    // 此时可以计算出该 U 型所能接受的水的面积为 (i - st.top() - 1) * (min(height[st.top()], height[i]) - height[top])。
    // 最后当前矩形进栈。
    // O(n)/O(n)
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            // 通过单调栈找 U 型槽
            while (!stk.empty() && height[i] >= height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                // stk.top() 为 U 型槽的左边界
                // height[i] 为 U 型槽的右边界
                //  height[top] 为 U 型槽的底部
                res += (i - stk.top() - 1) * (min(height[i], height[stk.top()]) - height[top]);
            }
            stk.push(i);
        }

        return res;
    }
};

class Solution {
public:
    // https://www.acwing.com/solution/content/121/
    // 三次线性扫描（空间可优化）
    // 每个矩形条上方所能接受的水的高度，是由它左边 最高的 矩形，和右边 最高的 矩形决定的。
    // 具体地，假设第 i 个矩形条的高度为 height[i]，且矩形条左边 最高的 矩形条的高度为 left_max[i]，
    // 右边 最高的 矩形条高度为 right_max[i]，
    // 则该矩形条上方能接受水的高度为 min(left_max[i], right_max[i]) - height[i]。
    // O(n)/O(n)
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        if (n == 0) return res;
        vector<int> lm(n), rm(n);

        lm[0] = height[0];
        for (int i = 1; i < n; i++) {
            lm[i] = max(lm[i - 1], height[i]);
        }
        rm[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rm[i] = max(rm[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++) {
            res += (min(lm[i], rm[i]) - height[i]);
        }

        return res;
    }
};

class Solution {
public:
    // 双指针法
    // 左右边界可只用一个变量表示
    // O(n)/O(1)
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int res = 0;
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                left_max = max(left_max, height[left]);  // 当前位置左边的最大高度
                res += (left_max - height[left]);        // 当前位置可储水量
                left++;
            } else {
                right_max = max(right_max, height[right]);
                res += (right_max - height[right]);
                right--;
            }
        }

        return res;
    }
};

class Solution {
public:
    // 动态规划
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 0) return 0;

        vector<int> left_max(len);  // 左边最大高度
        left_max[0] = height[0];
        for (int i = 1; i < len; i++) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        vector<int> right_max(len);  // 右边最大高度
        right_max[len - 1] = height[len - 1];
        for (int i = len - 2; i > 0; i--) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        int res = 0, ans = 0;
        for (int i = 1; i < len - 1; i++) {
            ans = min(left_max[i], right_max[i]);
            if (height[i] < ans) {
                res += (ans - height[i]);
            }
        }

        return res;
    }
};
