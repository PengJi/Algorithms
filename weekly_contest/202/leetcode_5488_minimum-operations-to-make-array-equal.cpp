/**
 * 5488. 使数组中所有元素相等的最小操作数
 * https://leetcode-cn.com/problems/minimum-operations-to-make-array-equal/
 */

class Solution {
public:
    // 等差数列求和
    int minOperations(int n) {
        return n * n / 4;
    }
};
