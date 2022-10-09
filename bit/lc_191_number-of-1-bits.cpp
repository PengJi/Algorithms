/**
 * 191. 位1的个数
 * 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。
 * 
 * https://leetcode-cn.com/problems/number-of-1-bits/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/number-of-1-bits/solution/wei-1de-ge-shu-by-leetcode/
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n != 0) {
            sum++;
            n &= (n - 1);
        }
        return sum;
    }
};

class Solution {
public:
    // 遍历每一位，判断是否为1
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
            // 依次右移 i 位
            res += n >> i & 1;
        }

        return res;
    }
};

class Solution {
public:
    // 使用 lowbit 计算
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            // n & -n 为 lowbit 操作，即获取最低位的1，比如 10100，则 lowbit 后为 100。
            // -n 为 n 的补码，即反码加一。
            n -= n & -n;
            res++;
        }

        return res;
    }
};
