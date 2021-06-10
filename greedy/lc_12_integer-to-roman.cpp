/**
 * 12. 整数转罗马数字
 * https://leetcode-cn.com/problems/integer-to-roman/
 */

class Solution {
public:
    // 贪心算法
    // https://leetcode-cn.com/problems/integer-to-roman/solution/tan-xin-suan-fa-by-liweiwei1419/
    string intToRoman(int num) {
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string ans = "";
        int idx = 0;
        while(idx < 13) {
            while(num >= nums[idx]) {
                ans += romans[idx];
                num -= nums[idx];
            }
            idx++;
        }

        return ans;
    }
};
