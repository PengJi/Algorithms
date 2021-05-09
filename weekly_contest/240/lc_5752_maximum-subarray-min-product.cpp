/**
 * 5752. 子数组最小乘积的最大值
 * https://leetcode-cn.com/problems/maximum-subarray-min-product/
 */

typedef long long LL;

const int N = 100010;

int h[N], l[N], r[N], q[N];
LL s[N];

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/1212402/
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i <= n; i ++ ) {
            h[i] = nums[i - 1];
            s[i] = s[i - 1] + h[i];
        }
        h[0] = h[n + 1] = 0;
        int tt = 0;
        q[0] = 0;
        for (int i = 1; i <= n; i ++ ) {
            while (h[i] <= h[q[tt]]) tt -- ;
            l[i] = q[tt];
            q[ ++ tt] = i;
        }
        tt = 0;
        q[0] = n + 1;
        for (int i = n; i; i -- ) {
            while (h[i] <= h[q[tt]]) tt -- ;
            r[i] = q[tt];
            q[ ++ tt] = i;
        }

        LL res = 0;
        for (int i = 1; i <= n; i ++ )
            res = max(res, h[i] * (s[r[i] - 1] - s[l[i]]));
        return res % 1000000007;
    }
};
