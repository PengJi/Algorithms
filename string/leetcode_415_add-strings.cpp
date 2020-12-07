/**
 * 415. 字符串相加
 * 给定两个字符串形式的非负整数 num1 和 num2 ，计算它们的和。
 * 
 * https://leetcode-cn.com/problems/add-strings/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/add-strings/solution/zi-fu-chuan-xiang-jia-by-leetcode-solution/
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int add = 0;

        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;

            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
