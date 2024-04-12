/**
 * 15. 三数之和
 * https://leetcode-cn.com/problems/3sum/
 */

class Solution {
public:
    // 排序 + 双指针
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(n)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back) {
                int sum = nums[front] + nums[back];
                
                if (sum < target) {
                    front++;
                } else if (sum > target) {
                    back--;
                } else {
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[front]);
                    tmp.push_back(nums[back]);
                    res.push_back(tmp);
                    tmp.clear();
                    
                    while (front < back && nums[front] == tmp[1]) front++;
                    while (front < back && nums[back] == tmp[2]) back--;
                }
            }

            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        
        return res;
    }
};
