/**
 * 18. 四数之和
 * https://leetcode-cn.com/problems/4sum/
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (i > 0 && i < n && nums[i] == nums[i - 1]) i++;

            for (int j = i + 1; j < n; j++) {
                while (j != i + 1 && j < n && nums[j] == nums[j - 1]) j++;
                int left = j + 1, right = n - 1;
                
                while (left < right) {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        do {
                            left++;
                        } while (left < right && nums[left - 1] == nums[left]);
                        do {
                            right--;
                        } while (left < right && nums[right] == nums[right + 1]);
                    } else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        do {
                            left++;
                        } while (left < right && nums[left - 1] == nums[left]);
                    } else {
                        do {
                            right--;
                        } while (left < right && nums[right] == nums[right + 1]);
                    }
                }
            }
        }
        return res;
    }
};
