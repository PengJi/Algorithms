/**
 * 2859. 计算 K 置位下标对应元素的和
 * https://leetcode.cn/problems/sum-of-values-at-indices-with-k-set-bits/description/
*/
class Solution {
public:
    // 暴力枚举
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        const int n = nums.size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < 10; j++)
                if ((i >> j) & 1)
                    ++cnt;

            if (cnt == k)
                ans += nums[i];
        }

        return ans;
    }
};
