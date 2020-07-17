/**
 * 16. 最接近的三数之和
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
 * 找出 nums 中的三个整数，使得它们的和与 target 最接近。
 * 返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * https://leetcode-cn.com/problems/3sum-closest/
 */

class Solution {
public:
    // 排序 + 双指针
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        int closest = nums[0]+nums[1]+nums[2];

        sort(nums.begin(), nums.end());

        for(int first = 0 ; first < nums.size()-2 ; ++first) {
            if(first > 0 && nums[first] == nums[first-1]) continue;
            int second = first+1;
            int third = nums.size()-1; 

            while(second < third) {
                int curSum = nums[first]+nums[second]+nums[third];
                if(curSum == target) return curSum;
                if(abs(target-curSum)<abs(target-closest)) {
                    closest = curSum;
                }
                if(curSum > target) {
                    --third;
                } else {
                    ++second;
                }
            }
        }

        return closest;
    }
};