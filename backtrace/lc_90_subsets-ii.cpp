/**
 * 90. 子集 II
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 * 
 * https://leetcode.cn/problems/subsets-ii/
 */

class Solution {
public:
    // 回溯法
    // https://leetcode-cn.com/problems/subsets-ii/solution/90zi-ji-2-hui-su-jian-zhi-by-huxn-4/
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        trackback(nums, 0, ans, path);
        return ans;
    }

    void trackback(vector<int>& nums, int begin, vector<vector<int>>& ans, vector<int> path) {
        ans.push_back(path);
        for(int i = begin; i < nums.size(); i++) {
            path.push_back(nums[i]);
            trackback(nums, i+1, ans, path);
            path.pop_back();
            while(i < nums.size()-1 && nums[i] == nums[i+1]){
                i++;
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            res.push_back(path);
            return;
        }

        int k = idx + 1;
        while(k < nums.size() && nums[k] == nums[idx]) k++;

        for(int i = 0; i <= k - idx; i++) {
            dfs(nums, k);
            path.push_back(nums[idx]);
        }

        for(int i = 0; i <= k - idx; i++) {
            path.pop_back();
        }
    }
};
