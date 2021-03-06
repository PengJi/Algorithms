/**
 * 1716. 计算力扣银行的钱
 * https://leetcode-cn.com/problems/calculate-money-in-leetcode-bank/
 */

class Solution {
public:
    int totalMoney(int n) {
        int total=0, week=0, offset=0;
        for(int i=0; i<n; i++){
            week = i / 7;
            offset = i % 7 + 1;
            total += week + offset;
        }
        return total;
    }
};
