/**
 * 150. 逆波兰表达式求值
 * https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 */

class Solution {
public:
    // 利用栈遍历
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        if (len == 0) return 0;

        int tmp1, tmp2;
        stack<int> stk;

        for (auto token : tokens) {
            if (token == "+") {
                tmp1 = stk.top();
                stk.pop();
                tmp2 = stk.top();
                stk.pop();
                stk.push(tmp1 + tmp2);
            } else if (token == "-") {
                tmp1 = stk.top();
                stk.pop();
                tmp2 = stk.top();
                stk.pop();
                stk.push(tmp2 - tmp1);
            } else if (token == "*") {
                tmp1 = stk.top();
                stk.pop();
                tmp2 = stk.top();
                stk.pop();
                stk.push(tmp1 * tmp2);
            } else if (token == "/") {
                tmp1 = stk.top();
                stk.pop();
                tmp2 = stk.top();
                stk.pop();
                stk.push(tmp2 / tmp1);
            } else {
                stk.push(atoi(token.c_str()));
            }
        }

        return stk.top();
    }
};
