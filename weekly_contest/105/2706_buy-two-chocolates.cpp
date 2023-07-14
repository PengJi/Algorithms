/**
 * 2706. 购买两块巧克力
 * https://leetcode.cn/problems/buy-two-chocolates/description/
*/

class Solution {
public:
    // 贪心
    int buyChoco(vector<int>& prices, int money) {
        int mi1 = INT_MAX, mi2 = INT_MAX;
        for (int x : prices) {
            if (x < mi1) {
                mi2 = mi1;
                mi1 = x;
            } else if (x < mi2) {
                mi2 = x;
            }
        }

        if (mi1 + mi2 > money)
            return money;

        return money - mi1 - mi2;
    }
};
