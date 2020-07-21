/**
 * 739. 每日温度
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
};
