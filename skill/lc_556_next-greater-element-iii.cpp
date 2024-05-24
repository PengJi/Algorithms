/**
 * 556. 下一个更大元素 III
 * https://leetcode.cn/problems/next-greater-element-iii/description/
 */

class Solution {
public:
    // 贪心
    // 我们把 n 看成一个字符串，这道题相当于求字符串的下一个排列。
    // 有关题解可以参考 LeetCode 31 题解 ，只不过这里的字符串是低位在低地址。
    int nextGreaterElement(int n) {
        string s;
        while (n) {
            s += (char)(n % 10 + '0');
            n /= 10;
        }
        int l = s.length();
        int j = -1;
        for (int i = 1; i < l; i++)
            if (s[i] < s[i - 1]) {
                j = i;
                break;
            }

        if (j == -1)
            return -1;

        for (int i = 0; i < j; i++)
            if (s[i] > s[j]) {
                swap(s[i], s[j]);
                break;
            }

        reverse(s.begin(), s.begin() + j);

        long long ans = 0;
        for (int i = l - 1; i >= 0; i--)
            ans = ans * 10 + s[i] - '0';

        if (ans >= 1ll << 31)
            ans = -1;
        return ans;
    }
};
