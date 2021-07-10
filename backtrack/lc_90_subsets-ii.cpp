/**
 * 90. 子集 II
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * https://leetcode-cn.com/problems/subsets-ii/
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
