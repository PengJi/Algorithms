/**
 * 258. 各位相加
 * 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
 */

class Solution {
public:
    // x * 100 + y * 10 + z = x * 99 + y * 9 + x + y + z
    // https://leetcode-cn.com/problems/add-digits/solution/java-o1jie-fa-de-ge-ren-li-jie-by-liveforexperienc/
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
