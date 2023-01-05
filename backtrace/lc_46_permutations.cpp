/**
 * 46. 全排列
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * https://leetcode-cn.com/problems/permutations/
 */

class Solution {
public:
    // 回溯
    // 时间复杂度：O(n!)
    // 空间复杂度：O(n! * m)
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        backtrack(nums, track, res);
        return res;
    }

    void backtrack(vector<int> nums, vector<int> track, vector<vector<int>> &res) {
        if(track.size() == nums.size()) {
            res.push_back(track);
            return;
        }

        bool flag = false;
        for(int i = 0; i < nums.size(); i++) {
            // 判断元素是否在路径中
            for(int j = 0; j < track.size(); j++){
                if(track[j] == nums[i]){
                    flag = true;
                    break;
                }
            }
            
            if(flag){
                flag = false;
                continue;
            }

            track.push_back(nums[i]);
            backtrack(nums, track, res);
            track.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> st;  // 当前位置是否被占用
    vector<int> path;

    vector<vector<int>> permute(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++ ) st.push_back(false);
        dfs(0, nums);
        return ans;
    }

    void dfs(int idx, vector<int> &nums)
    {
        if (idx == nums.size()) {
            ans.push_back(path);
            return ;
        }

        for (int i = 0; i < nums.size(); i++)
            if (!st[i]) {
                st[i] = true;
                path.push_back(nums[i]);
                dfs(nums, idx + 1);
                st[i] = false;
                path.pop_back();
            }
    }
};
