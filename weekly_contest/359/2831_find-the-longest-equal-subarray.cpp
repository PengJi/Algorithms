/**
 * 2831. 找出最长等值子数组
 * https://leetcode.cn/problems/find-the-longest-equal-subarray/description/
*/
class Solution {
public:
    // 双指针
    int longestEqualSubarray(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<vector<int>> p(n);

        for (int i = 0; i < n; i++)
            p[nums[i] - 1].push_back(i);

        int ans = 0;
        for (int num = 0; num < n; num++) {
            int tot = 0, ma = 1;
            for (int i = 1, j = 0; i < p[num].size(); i++) {
                tot += p[num][i] - p[num][i - 1] - 1;

                while (tot > k) {
                    tot -= p[num][j + 1] - p[num][j] - 1;
                    ++j;
                }

                ma = max(ma, i - j + 1);
            }

            ans = max(ans, ma);
        }

        return ans;
    }
};
