/**
 * 2710. 移除字符串中的尾随零
 * https://leetcode.cn/problems/remove-trailing-zeros-from-a-string
*/

class Solution {
public:
    string removeTrailingZeros(string num) {
        while (num.size() > 1 && num.back() == '0')
            num.pop_back();

        return num;
    }
};
