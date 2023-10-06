/**
 * 2806. 取整购买后的账户余额
 * https://leetcode.cn/problems/account-balance-after-rounded-purchase/description/
*/
class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        if (purchaseAmount % 10 < 5)
            return 100 - purchaseAmount + purchaseAmount % 10;

        return 90 - purchaseAmount + purchaseAmount % 10;
    }
};
