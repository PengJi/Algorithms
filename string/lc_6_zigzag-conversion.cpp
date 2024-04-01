/**
 * 6. Z 字形变换
 * https://leetcode-cn.com/problems/zigzag-conversion/
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string res;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                res += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    res += s[j + cycleLen - i];
            }
        }
        return res;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int offset = 2 * (numRows - 1);
        string res;

        for (int i = 0; i < numRows; i++) {    // 遍历每一行
            if (i == 0 || i == numRows - 1) {  // 第一行和最后一行
                for (int j = i; j < s.size(); j += offset) {
                    res += s[j];
                }
            } else {  // 其余行
                for (int m = i, n = numRows * 2 - 1 - i - 1;
                     m < s.size() || n < s.size();
                     m += offset, n += offset) {
                    if (m < s.size()) res += s[m];
                    if (n < s.size()) res += s[n];
                }
            }
        }

        return res;
    }
};
