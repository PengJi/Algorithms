/**
 * 66. 加一
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * https://leetcode-cn.com/problems/plus-one/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/plus-one/solution/hua-jie-suan-fa-66-jia-yi-by-guanpengchn/
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();

        for(int i = len - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] %= 10;
            if(digits[i] != 0) return digits;
        }

        vector<int> res(len+1, 0);
        res[0] = 1;

        return res;
    }
};
