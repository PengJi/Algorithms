/**
 * 2815. 数组中的最大数对和
 * https://leetcode.cn/problems/max-pair-sum-in-an-array/description/
*/
class Solution {
public:
    int maxSum(vector<int>& nums) {
        const int n = nums.size();

        vector<int> p(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i], ma = 0;
            while (x) {
                ma = max(ma, x % 10);
                x /= 10;
            }
            p[i] = ma;
        }

        int ans = -1;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (p[i] == p[j])
                    ans = max(ans, nums[i] + nums[j]);

        return ans;
    }
};
