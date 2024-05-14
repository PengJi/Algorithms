/**
 * 15. 三数之和
 * https://leetcode-cn.com/problems/3sum/
 */

class Solution {
public:
    // 排序 + 双指针
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(n)
    // https://www.acwing.com/solution/content/60/
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            while (i != 0 && i < n && nums[i] == nums[i - 1]) i++;

            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    do {
                        left++;
                    } while (left < right && nums[left - 1] == nums[left]);
                    do {
                        right--;
                    } while (left < right && nums[right] == nums[right + 1]);
                } else if (nums[i] + nums[left] + nums[right] < 0) {
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

        return res;
    }
};
