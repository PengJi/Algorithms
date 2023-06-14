/**
 * 2654. 使数组所有元素变成 1 的最少操作次数
 * https://leetcode.cn/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/
*/
const int N = 60;

class Solution {
public:
    int g[6][N], log[N];

    bool check(int len, int n) {
        int z = log[len];

        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;

            if (gcd(g[z][i], g[z][j - (1 << z) + 1]) == 1)
                return true;
        }

        return false;
    }

    int minOperations(vector<int>& nums) {
        const int n = nums.size();

        int one = 0;
        for (int x : nums)
            if (x == 1)
                one++;

        if (one > 0)
            return n - one;

        for (int i = 0; i < n; i++)
            g[0][i] = nums[i];

        log[1] = 0;
        for (int i = 2; i <= n; i++)
            log[i] = (i >> (log[i - 1] + 1)) ? log[i - 1] + 1 : log[i - 1];

        for (int i = 1; i <= log[n]; i++)
            for (int j = 0; j < n - (1 << i) + 1; j++)
                g[i][j] = gcd(g[i - 1][j], g[i - 1][j + (1 << (i - 1))]);

        int l = 2, r = n + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid, n)) r = mid;
            else l = mid + 1;
        }

        if (l == n + 1)
            return -1;

        return n + l - 2;
    }
};
