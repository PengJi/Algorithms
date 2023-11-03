/**
 * 2834. 找出美丽数组的最小和
 * https://leetcode.cn/problems/find-the-minimum-possible-sum-of-a-beautiful-array/description/
*/
class Solution {
public:
    int minimumPossibleSum(int n, int k) {
        long long m = min(k / 2, n);
        return (m * (m + 1) + (n - m - 1 + k * 2) * (n - m)) / 2 % 1000000007;
    }
};
