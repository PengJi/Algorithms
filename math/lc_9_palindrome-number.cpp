/**
 * 9. 回文数
 * https://leetcode-cn.com/problems/palindrome-number/
 */

class Solution {
public:
    // 遍历一半
    // 时间复杂度：O(logn)
    // 空间复杂度：O(1)
    bool isPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber / 10;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int y = x;
        long long res = 0;
        while(x) {
            res = res * 10 + x % 10;
            x /= 10;
        }

        return res == y;
    }
};

class Solution {
public:
    // 算出后一半的逆序值是否等于前一半。边生成边比较。
    // 时间复杂度为 O(n)
    bool isPalindrome(int x) {
        if(x < 0 || x && x % 10 == 0) return false;  // 特判情况：负数、0、<=10
        int s = 0;
        while(s <= x) {
            s = s * 10 + x % 10;  // 后一遍的逆序值
            if(s == x || s == x/10) return true;  // 判断是否等于前一半
            x /= 10;
        }
        return false;
    }
};
