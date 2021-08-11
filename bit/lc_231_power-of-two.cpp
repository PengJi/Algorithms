/**
 * 231. 2的幂
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 * 
 * https://leetcode-cn.com/problems/power-of-two/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/power-of-two/solution/power-of-two-er-jin-zhi-ji-jian-by-jyd/
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
