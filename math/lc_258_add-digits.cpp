/**
 * 258. 各位相加
 * 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
 * https://leetcode.cn/problems/add-digits/
 */

class Solution {
public:
    // x * 100 + y * 10 + z = x * 99 + y * 9 + x + y + z
    // https://leetcode-cn.com/problems/add-digits/solution/java-o1jie-fa-de-ge-ren-li-jie-by-liveforexperienc/
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};

class Solution {
public:
    // 模拟方法
    int addDigits(int num) {
        while(num >=  10) {
            int tot = 0;
            while(num > 0) {
                tot += (num % 10);
                num /= 10;
            }
            num = tot;
        }

        return num;
    }
};

class Solution {
public:
    // 数论
    // 判断这个数字模 9 之后的余数（若余 0 则返回 9）。
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
