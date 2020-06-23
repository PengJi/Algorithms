/**
 * 78. 子集
 * https://leetcode-cn.com/problems/subsets/
 */

class Solution {
public:
    vector<vector<int>> res;

    // 回溯
    // 时间复杂度：O(N!)
    // 空间复杂度：O()
    vector<vector<int>> subsets(vector<int>& nums) {
        // 记录走过的路径
        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& track) {
        res.push_back(track);
        for (int i = start; i < nums.size(); i++) {
            // 做选择
            track.push_back(nums[i]);
            // 回溯
            backtrack(nums, i + 1, track);
            // 撤销选择
            track.pop_back();
        }
    }
};