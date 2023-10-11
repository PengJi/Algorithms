/**
 * 2809. 使数组和小于等于 x 的最少时间
 * https://leetcode.cn/problems/minimum-time-to-make-array-sum-at-most-x/description/
*/
class Solution {
public:
    // 动态规划
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        const int n = nums1.size();
        const int INF = 1000000000;

        vector<int> id(n);

        for (int i = 0; i < n; i++)
            id[i] = i;

        sort(id.begin(), id.end(), [&](int x, int y) {
            return nums2[x] < nums2[y];
        });

        vector<int> f(n + 1, INF);
        f[0] = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j >= 0; j--) {
                f[j] += nums1[id[i]] + j * nums2[id[i]];
                if (j > 0)
                    f[j] = min(f[j], f[j - 1] + sum);
            }

            sum += nums2[id[i]];
        }

        for (int j = 0; j <= n; j++)
            if (f[j] <= x)
                return j;

        return -1;
    }
};
