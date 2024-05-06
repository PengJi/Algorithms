/**
 * 8. 字符串转换整数 (atoi)
 * https://leetcode-cn.com/problems/string-to-integer-atoi/
 */

class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int n = s.size();
        if (n == 0) return res;
        int k = 0;

        // 取出前导空白字符
        while (k < n && s[k] == ' ') k++;
        if (k == n) return res;

        // 判断符号
        int sign = 1;
        if (s[k] == '-') {
            sign = -1;
            k++;
        } else if (s[k] == '+') {
            k++;
        }

        // 计算数值
        while (k < n && s[k] >= '0' && s[k] <= '9') {
            int x = s[k] - '0';
            if (sign == 1) {
                // res * 10 + x > INT_MAX
                if (res > (INT_MAX - x) / 10) return INT_MAX;
            } else if (sign == -1) {  // 负数当成正数计算
                x = -x;
                // -res * 10 -x < INT_MIN
                if (res < (INT_MIN - x) / 10) return INT_MIN;
            }
            res = res * 10 + x;
            k++;
        }

        return res;
    }
};
