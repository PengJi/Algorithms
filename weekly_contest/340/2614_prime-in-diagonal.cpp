/**
 * 2614. 对角线上的质数
 * https://leetcode.cn/problems/prime-in-diagonal/
*/
class Solution {
public:
    bool is_prime(int x) {
        if (x <= 1)
            return false;

        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;

        return true;
    }

    // 模拟
    int diagonalPrime(vector<vector<int>>& nums) {
        const int n = nums.size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (is_prime(nums[i][i]))
                ans = max(ans, nums[i][i]);

            if (is_prime(nums[i][n - i - 1]))
                ans = max(ans, nums[i][n - i - 1]);
        }

        return ans;
    }
};
