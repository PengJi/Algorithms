/**
 * 2652. 倍数求和
 * https://leetcode.cn/problems/sum-multiples/
*/
class Solution {
public:
    int sumOfMultiples(int n) {
        return 3 * sum(n / 3) + 5 * sum(n / 5) + 7 * sum(n / 7)
            - 15 * sum(n / 15) - 21 * sum(n / 21) - 35 * sum(n / 35)
            + 105 * sum(n / 105);
    }

    inline int sum(int x) {
        return (1 + x) * x / 2;
    }
};
