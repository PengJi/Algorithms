/**
 * 2864. 最大二进制奇数
 * https://leetcode.cn/problems/maximum-odd-binary-number/description/
*/
class Solution {
public:
    // 贪心
    string maximumOddBinaryNumber(string s) {
        const int n = s.size();

        int one = 0;
        for (char c : s)
            if (c == '1')
                ++one;

        for (int i = 0; i < one - 1; i++)
            s[i] = '1';

        for (int i = one - 1; i < n - 1; i++)
            s[i] = '0';

        s[n - 1] = '1';

        return s;
    }
};
