/**
 * 263. 丑数
 * 编写一个程序判断给定的数是否为丑数。
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

class Solution {
public:
    // 使用除法去掉质因子
    bool isUgly(int n) {
        if(n <= 0) return false;

        while(n % 2 == 0) n /= 2;
        while(n % 3 == 0) n /= 3;
        while(n % 5 == 0) n /= 5;

        return n == 1;
    }
};
