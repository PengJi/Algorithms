/**
 * 47. 全排列 II
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 *
 * https://leetcode-cn.com/problems/permutations-ii/
 */

class Solution {
public:
    vector<int> vis;

    // 回溯法
    // https://leetcode-cn.com/problems/permutations-ii/solution/quan-pai-lie-ii-by-leetcode-solution/
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
        if (idx == nums.size()) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }
};

class Solution {
public:
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> ans;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        st = vector<bool>(nums.size(), false);
        path = vector<int>(nums.size());
        dfs(nums, 0, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int idx, int start) {
        if (idx == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i++)
            if (!st[i]) {
                st[i] = true;
                path[i] = nums[idx];
                if (idx + 1 < nums.size() && nums[idx + 1] != nums[idx])  // 与前一个算法的不同之处
                    dfs(nums, idx + 1, 0);
                else
                    dfs(nums, idx + 1, i + 1);
                st[i] = false;
            }
    }
};
