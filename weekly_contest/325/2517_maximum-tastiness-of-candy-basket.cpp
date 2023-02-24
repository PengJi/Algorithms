/**
 * 2517. 礼盒的最大甜蜜度
 * https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/
*/

class Solution {
private:
    bool check(int d, const vector<int> &price, int k) {
        const int n = price.size();

        int prev = 0, cnt = 1;
        for (int i = 1; i < n; i++)
            if (price[i] - price[prev] >= d) {
                cnt++;
                prev = i;
            }

        return cnt >= k;
    }

public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());

        int l = 0, r = 1000000000;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid + 1, price, k))
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }
};
