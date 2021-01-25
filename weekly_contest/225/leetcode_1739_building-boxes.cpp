/**
 * 1739. 放置盒子
 * https://leetcode-cn.com/problems/building-boxes/
 */

class Solution {
public:
    // https://leetcode-cn.com/contest/weekly-contest-225/ranking/
    // 6
    int minimumBoxes(int n) {
        long long int c = 0;
        long long int res = 0;
        long long int i;
        for (i = 1; c <= n; i++) {
            c += (1 + i) * i / 2;
            res += i;
        }
        i--;
        res -= i;
        c -= (1 + i) * i / 2;
        n -= c;
        for (i = 1; n > 0; i++) {
            res++;
            n -= i;
        }
        return res;
    }
};
