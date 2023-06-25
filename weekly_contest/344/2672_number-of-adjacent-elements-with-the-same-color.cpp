/**
 * 2672. 有相同颜色的相邻元素数目
 * https://leetcode.cn/problems/number-of-adjacent-elements-with-the-same-color/
*/
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n, 0);

        const int m = queries.size();
        vector<int> ans(m);

        int cur = 0;
        for (int i = 0; i < m; i++) {
            int idx = queries[i][0], col = queries[i][1];
            if (idx > 0) {
                if (nums[idx] > 0 && nums[idx - 1] == nums[idx]) --cur;
                if (nums[idx - 1] == col) ++cur;
            }

            if (idx < n - 1) {
                if (nums[idx] > 0 && nums[idx] == nums[idx + 1]) --cur;
                if (col == nums[idx + 1]) ++cur;
            }

            nums[idx] = col;
            ans[i] = cur;
        }

        return ans;
    }
};
