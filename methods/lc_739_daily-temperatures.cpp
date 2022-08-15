/**
 * 739. 每日温度
 * 请根据每日 气温 列表，重新生成一个列表。
 * 对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。
 * 如果气温在这之后都不会升高，请在该位置用 0 来代替。
 * 
 * https://leetcode-cn.com/problems/daily-temperatures/
 */

class Solution {
public:
    // 单调栈（递减）
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.size() == 0) return {};

        vector<int> res(T.size(), 0);
        stack<int> stk;
        int left, right, cur;
        for(int i = 0; i < T.size(); i++) {
            while(!stk.empty() && T[stk.top()] < T[i]) {
                cur = stk.top();
                stk.pop();
                left = cur;
                right = i;
                res[cur] = right - left;
            }

            stk.push(i);
        }

        return res;
    }

    // 单调栈
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size());
        for(int i = temperatures.size()-1; i >= 0; i--) {
            while(stk.size() && temperatures[i] >= temperatures[stk.top()]) {
                stk.pop();
            }
            if(stk.size()) res[i] = stk.top() - i;
            stk.push(i);
        }

        return res;
    }
};
