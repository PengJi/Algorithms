/**
 * 2513. 最小化两个数组中的最大值
 * https://leetcode.cn/problems/minimize-the-maximum-of-two-arrays/
*/
#define LL long long

class Solution {
private:
    bool check(LL n, LL lcm, int d1, int d2, int u1, int u2) {
        LL both = n - n / d1 - n / d2 + n / lcm;

        LL o1 = n / d2 - n / lcm;

        LL o2 = n / d1 - n / lcm;

        u1 = max(u1 - o1, 0ll);
        u2 = max(u2 - o2, 0ll);

        return both >= u1 + u2;
    }

public:
    // 二分
    int minimizeSet(int d1, int d2, int u1, int u2) {
        LL lcm = (LL)(d1) / __gcd(d1, d2) * d2;

        LL l = u1 + u2, r = 2 * (u1 + u2);

        while (l < r) {
            LL mid = (l + r) >> 1;
            if (check(mid, lcm, d1, d2, u1, u2))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};
