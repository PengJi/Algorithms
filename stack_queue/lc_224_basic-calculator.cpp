/**
 * 224. 基本计算器
 * https://leetcode-cn.com/problems/basic-calculator/
 */

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/432768/
    void eval(stack<int>& num, stack<char>& op) {
        auto b = num.top();
        num.pop();
        auto a = num.top();
        num.pop();
        auto c = op.top();
        op.pop();
        int r;
        if (c == '+')
            r = a + b;
        else
            r = a - b;
        num.push(r);
    }

    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        for (int i = 0; i < s.size(); i++) {
            auto c = s[i];
            if (c == ' ') continue;
            if (isdigit(c)) {
                int x = 0, j = i;
                while (j < s.size() && isdigit(s[j])) x = x * 10 + (s[j++] - '0');
                i = j - 1;
                num.push(x);
            } else if (c == '(')
                op.push(c);
            else if (c == ')') {
                while (op.top() != '(') eval(num, op);
                op.pop();
            } else {
                if (!i || s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')  // 特殊处理符号和正号
                    num.push(0);
                while (op.size() && op.top() != '(') eval(num, op);
                op.push(c);
            }
        }
        while (op.size()) eval(num, op);
        return num.top();
    }
};
