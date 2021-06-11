/**
 * 415. 字符串相加
 * 给定两个字符串形式的非负整数 num1 和 num2 ，计算它们的和。
 * 
 * https://leetcode-cn.com/problems/add-strings/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/add-strings/solution/zi-fu-chuan-xiang-jia-by-leetcode-solution/
    // 时间复杂度：O(max(m, n))
    // 空间复杂度：O(1)
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        // 分别表示两位之和、进位、当前结果
        int tmp = 0, carry = 0, ans = "";

        int x, y;
        while(i >= 0 || j >= 0 || carry != 0) {
            x = i >= 0 ? num1[i] - '0' : 0;
            y = j >= 0 ? num2[j] - '0' : 0;

            tmp = x + y + carry;  // 计算两位之和
            carry = tmp / 10;  // 计算进位
            ans += '0' + tmp % 10;  // 计算当前结果，注意这里是逆序
            i -= 1;
            j -= 1;
        }

        reverse(ans.begin(), ans.end());  // 反转
        return ans;
    }
};
