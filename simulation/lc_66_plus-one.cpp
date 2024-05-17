/**
 * 66. 加一
 * https://leetcode-cn.com/problems/plus-one/
 */

class Solution {
public:
    // 主要处理进位
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();

        for (int i = len - 1; i >= 0; i--) {
            digits[i]++;  // 当前位+1
            digits[i] %= 10;
            if (digits[i] != 0) return digits;  // 当前为不为0则不需要进位，则直接返回
        }

        // 特殊情况，对于 9、99 这种，位数加一
        vector<int> res(len + 1, 0);
        res[0] = 1;
        return res;
    }
};
