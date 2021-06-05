/**
 * 263. 丑数
 * 编写一个程序判断给定的数是否为丑数。
 * 
 * https://leetcode-cn.com/problems/ugly-number/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/ugly-number/solution/java-zhi-xing-yong-shi-1-ms-zai-suo-you-java-ti-6/
    bool isUgly(int num) {
        if (num < 1) return false;
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        return num == 1;
    }
};
