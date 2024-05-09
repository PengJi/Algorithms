/**
 * 6. Z 字形变换
 * https://leetcode-cn.com/problems/zigzag-conversion/
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int len = s.size();
        int offset = (numRows - 1) * 2;  // 注意：步长
        string res = "";

        for (int i = 0; i < numRows; i++) {    // 遍历每一行
            if (i == 0 || i == numRows - 1) {  // 第一行和最后一行
                for (int j = i; j < len; j += offset) {
                    res += s[j];
                }
            } else {  // 注意：其余行，m/n 分别对应第一个元素与第二个元素，步长都是 offset
                for (int m = i, n = offset - i; m < len || n < len; m += offset, n += offset) {
                    if (m < len) res += s[m];
                    if (n < len) res += s[n];
                }
            }
        }

        return res;
    }
};
