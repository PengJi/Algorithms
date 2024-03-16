/**
 * 367. 有效的完全平方数
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 说明：不要使用任何内置的库函数，如  sqrt。
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/
 */

class Solution {
public:
    // 二分查找
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    bool isPerfectSquare(int num) {
        if (num < 2) return true;

        long left = 2, right = num / 2;  // 设置左边界与右边界
        long x, guessSquared;
        while (left <= right) {
            x = left + (right - left) / 2;
            guessSquared = x * x;

            if (guessSquared == num) {
                return true;
            }
            // 重置边界
            if (guessSquared > num) {
                right = x - 1;
            } else {
                left = x + 1;
            }
        }

        return false;
    }
};
