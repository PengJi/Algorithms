/**
 * 2829. k-avoiding 数组的最小总和
 * https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/description/
*/
class Solution {
public:
    int minimumSum(int n, int k) {
        int m = k / 2;

        if (n <= m)
            return (n + 1) * n / 2;

        return (m + 1) * m / 2 + (k + k + (n - m - 1)) * (n - m) / 2;
    }
};
