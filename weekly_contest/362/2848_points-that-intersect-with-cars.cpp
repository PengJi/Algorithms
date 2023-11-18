/**
 * 2848. 与车相交的点
 * https://leetcode.cn/problems/points-that-intersect-with-cars/description/
*/
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        const int n = nums.size();

        sort(nums.begin(), nums.end());

        int st = nums[0][0], ed = nums[0][1], ans = 0;
        for (int i = 1; i < n; i++) {
            if (ed < nums[i][0]) {
                ans += ed - st + 1;
                st = nums[i][0];
            }

            ed = max(ed, nums[i][1]);
        }

        ans += ed - st + 1;

        return ans;
    }
};
