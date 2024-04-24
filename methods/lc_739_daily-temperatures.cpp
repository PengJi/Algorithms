/**
 * 739. 每日温度
 * https://leetcode-cn.com/problems/daily-temperatures/
 */

class Solution {
public:
    // 单调栈
    // 从前向后遍历
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> stk;

        int cur;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                cur = stk.top();
                stk.pop();
                res[cur] = i - cur;
            }

            stk.push(i);
        }

        return res;
    }
};

class Solution {
public:
    // 单调栈
    // 从后向前遍历
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size());

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (stk.size() && temperatures[i] >= temperatures[stk.top()]) stk.pop();

            if (stk.size()) res[i] = stk.top() - i;
            stk.push(i);
        }

        return res;
    }
};
