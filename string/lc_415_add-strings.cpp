/**
 * 415. 字符串相加
 * https://leetcode-cn.com/problems/add-strings/
 */

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;
        int x, y, sum;
        string res = "";

        while (i >= 0 || j >= 0 || carry != 0) {
            x = i >= 0 ? num1[i] - '0' : 0;
            y = j >= 0 ? num2[j] - '0' : 0;
            sum = x + y + carry;      // 计算两位之和
            res += ('0' + sum % 10);  // 计算当前结果，注意这里是逆序
            carry = sum / 10;         // 计算进位
            i--;
            j--;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
