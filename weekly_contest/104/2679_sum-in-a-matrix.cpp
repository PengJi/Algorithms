/**
 * 2679. 矩阵中的和
 * https://leetcode.cn/problems/sum-in-a-matrix/
*/
class Solution {
public:
    // 排序
    int matrixSum(vector<vector<int>>& nums) {
        const int m = nums.size();
        const int n = nums[0].size();

        for (int i = 0; i < m; i++)
            sort(nums[i].begin(), nums[i].end());

        int ans = 0;
        for (int j = 0; j < n; j++) {
            int ma = 0;

            for (int i = 0; i < m; i++)
                ma = max(ma, nums[i][j]);

            ans += ma;
        }

        return ans;
    }
};
