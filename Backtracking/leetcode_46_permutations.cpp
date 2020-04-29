/**
 * 46. 全排列
 * https://leetcode-cn.com/problems/permutations/
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        backtrack(nums, track, res);
        return res;
    }

    void backtrack(vector<int> nums, vector<int> track, vector<vector<int>> &res){
        if(track.size() == nums.size()){
            res.push_back(track);
            return;
        }

        bool flag = false;
        for(int i = 0; i < nums.size(); i++){
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