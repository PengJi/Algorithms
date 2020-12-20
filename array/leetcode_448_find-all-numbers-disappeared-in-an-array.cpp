/**
 * 448. 找到所有数组中消失的数字
 * https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int new_index = abs(nums[i]) - 1;
            if(nums[new_index] > 0) {
                nums[new_index] *= -1;
            }
        }

        vector<int> ans;
        for(int i = 1; i <= nums.size(); i++) {
            if(nums[i - 1] > 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
